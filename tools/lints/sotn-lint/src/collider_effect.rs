use lazy_static::lazy_static;

use crate::bit_flag_line_transformer::BitFlagLineTransformer;
use crate::line_transformer::LineTransformer;

pub struct ColliderEffectTransformer {
    transformer: BitFlagLineTransformer<u32>,
}

lazy_static! {
    static ref COLLIDER_EFFECTS: [(u32, &'static str); 16] = [
        (1 << 0,  "EFFECT_SOLID"),
        (1 << 1,  "EFFECT_UNK_0002"),
        (1 << 2,  "EFFECT_QUICKSAND"),
        (1 << 3,  "EFFECT_WATER"),
        (1 << 4,  "EFFECT_MIST_ONLY"),
        (1 << 5,  "EFFECT_UNK_0020"),
        (1 << 6,  "EFFECT_SOLID_FROM_ABOVE"),
        (1 << 7,  "EFFECT_SOLID_FROM_BELOW"),
        (1 << 8,  "EFFECT_UNK_0100"),
        (1 << 9,  "EFFECT_UNK_0200"),
        (1 << 10, "EFFECT_UNK_0400"),
        (1 << 11, "EFFECT_UNK_0800"),
        (1 << 12, "EFFECT_UNK_1000"),
        (1 << 13, "EFFECT_UNK_2000"),
        (1 << 14, "EFFECT_UNK_4000"),
        (1 << 15, "EFFECT_UNK_8000"),
    ];
}

impl ColliderEffectTransformer {
    pub fn new() -> Self {
        Self {
            transformer: BitFlagLineTransformer::<u32>::new(
                "effects",
                "0",
                &COLLIDER_EFFECTS.iter().collect(),
            ),
        }
    }
}

impl LineTransformer for ColliderEffectTransformer {
    fn transform_line(&self, line: &str) -> String {
        self.transformer.transform_line(line)
    }
}
