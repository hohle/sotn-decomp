use lazy_static::lazy_static;

use crate::line_transformer::LineTransformer;
use crate::enum_line_transformer::EnumLineTransformer;

pub struct PlayerStepTransformer {
    transformer: EnumLineTransformer<u16>,
}

lazy_static! {
    static ref TYPES: [(u16, &'static str); 43] = [
        (0, "Player_Stand"),
        (1, "Player_Walk"),
        (2, "Player_Crouch"),
        (3, "Player_Fall"),
        (4, "Player_Jump"),
        (5, "Player_MorphBat"),
        (6, "Player_AlucardStuck"),
        (7, "Player_MorphMist"),
        (8, "Player_HighJump"),
        (9, "Player_UnmorphBat"),
        (10, "Player_Hit"),
        (11, "Player_StatusStone"),
        (12, "Player_BossGrab"),
        (13, "Player_KillWater"),
        (14, "Player_UnmorphMist"),
        (15, "Player_SwordWarp"),
        (16, "Player_Kill"),
        (17, "Player_Unk17"),
        (18, "Player_Teleport"),
        (19, "Player_FlameWhip"),
        (20, "Player_Hydrostorm"),
        (21, "Player_ThousandBlades"),
        (22, "Player_RichterFourHolyBeasts"),
        (23, "Player_Slide"),
        (24, "Player_MorphWolf"),
        (25, "Player_UnmorphWolf"),
        (26, "Player_SlideKick"),
        (27, "Player_Unk27"),
        (32, "Player_SpellDarkMetamorphosis"),
        (33, "Player_SpellSummonSpirit"),
        (34, "Player_SpellHellfire"),
        (35, "Player_SpellTetraSpirit"),
        (36, "Player_Spell36"),
        (37, "Player_SpellSoulSteal"),
        (38, "Player_Unk38"),
        (39, "Player_SpellSwordBrothers"),
        (40, "Player_AxearmorStand"),
        (41, "Player_AxearmorWalk"),
        (42, "Player_AxearmorJump"),
        (43, "Player_AxearmorHit"),
        (48, "Player_Unk48"),
        (49, "Player_Unk49"),
        (50, "Player_Unk50"),
    ];
}

impl PlayerStepTransformer {
    pub fn new() -> Self {
        Self {
            transformer: EnumLineTransformer::<u16>::new(
                Some("PLAYER"), "step", &TYPES.iter().collect()),
        }
    }
}

impl LineTransformer for PlayerStepTransformer {
    fn transform_line(&self, line: &str) -> String {
        self.transformer.transform_line(line)
    }
}
