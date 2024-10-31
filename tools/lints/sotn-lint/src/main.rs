use std::fs::File;
use std::io::{BufRead, BufReader, Write};

mod bit_flag_line_transformer;
mod collider_effect;
mod drawflags;
mod drawmodes;
mod enum_line_transformer;
mod enum_statement;
mod fixed;
mod flags;
mod line_transformer;
mod player_status;
mod player_step;
mod primitive_type;
mod relics;

use collider_effect::ColliderEffectTransformer;
use drawflags::DrawFlagsTransformer;
use drawmodes::DrawModeTransformer;
use fixed::FixedTransformer;
use flags::FlagsTransformer;
use line_transformer::LineTransformer;
use player_status::PlayerStatusTransformer;
use player_step::PlayerStepTransformer;
use primitive_type::PrimitiveTypeTransformer;
use rayon::prelude::*;
use relics::RelicsTransformer;

fn transform_file(file_path: &str, transformers: &Vec<Box<dyn LineTransformer>>) -> usize {
    let mut alterations = 0;
    let mut lines = Vec::new();
    let mut original_lines = Vec::new();

    let file = File::open(file_path).expect("Unable to open file");
    let reader = BufReader::new(file);
    for line in reader.lines() {
        let mut line_str = line.unwrap();
        original_lines.push(line_str.clone());

        for transformer in transformers {
            line_str = transformer.transform_line(&line_str);
        }

        lines.push(line_str);
    }

    if let Some(_) = original_lines.iter().zip(lines.iter()).position(|(a, b)| a != b) {

        let mut file = File::create(file_path).expect("Unable to create file");
        for (i, line) in lines.iter().enumerate() {
            if lines[i] != original_lines[i] {
                alterations += 1;
                println!("{}: {} -> {}", i, original_lines[i], lines[i]);
            }
            writeln!(file, "{}", line).expect("Unable to write line to file");
        }
    }

    alterations
}

fn process_directory(dir_path: &str) {
    let transformers: Vec<Box<dyn LineTransformer>> = vec![
        Box::new(FixedTransformer),
        Box::new(RelicsTransformer),
        Box::new(DrawModeTransformer::new()),
        Box::new(FlagsTransformer::new()),
        Box::new(DrawFlagsTransformer::new()),
        Box::new(PrimitiveTypeTransformer::new()),
        Box::new(PlayerStatusTransformer::new()),
        Box::new(PlayerStepTransformer::new()),
        Box::new(ColliderEffectTransformer::new()),
    ];

    let entries = std::fs::read_dir(dir_path).expect("Unable to read directory");

    entries.par_bridge().for_each(|entry| {
        if let Ok(entry) = entry {
            let item_path = entry.path();
            if item_path.is_file() &&
                (item_path.to_string_lossy().ends_with(".c") ||
                 item_path.to_string_lossy().ends_with(".h")) {
                println!("checking {:?}", item_path);
                transform_file(&item_path.to_string_lossy(), &transformers);
            } else if item_path.is_dir() {
                if item_path.file_name().unwrap() != "mednafen" {
                    process_directory(&item_path.to_string_lossy());
                }
            }
        }
    });
}

fn main() {
    process_directory(&std::env::args().nth(1).expect("Missing directory path"));
}
