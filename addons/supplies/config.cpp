#define MAG_XX(a,b) class _xx_##a { magazine = a; count = b; }
#define WEAP_XX(a,b) class _xx_##a { weapon = a; count = b; }
#define ITEM_XX(a,b) class _xx_##a { name = a; count = b; }

class CfgPatches {
    class Tenthed_Supplies {
        author = "Akira";
        name = "10th JTF: Supplies";
        requiredAddons[] = {};
        weapons[] = {};
        units[] = {
            "Tenthed_Restricted_Arsenal",
            "Tenthed_Resupply_Weapons",
            "Tenthed_Resupply_Explosives",
            "Tenthed_Resupply_Medical",
            "Tenthed_Resupply_Emergency",
            "Tenthed_Resupply_Misc"
        };
    };
};
class CfgVehicles {
    //class EventHandlers;

    class CargoNet_01_box_F;
    class Tenthed_Restricted_Arsenal : CargoNet_01_box_F {
        displayName = "[10th] Arsenal";
        editorCategory = "Tenthed_EditorCategory_Items";
        editorSubcategory = "Tenthed_EditorSubcategory_Objects_Supplies";
        //class EventHandlers {
        //    init = "[_this, true] execVM call Tenthed_fnc_Arsenal;";
        //};
        class EventHandlers {
            //init = "(_this select 0) addAction ['Open Arsenal', {hint 'This is your Arsenal!'}];";
            init = "(_this select 0) call Tenthed_fnc_Arsenal;";
        };
        class TransportMagazines { };
        class TransportWeapons { };
        //class TransportBackpacks { };
        class TransportItems {
            //ITEM_XX(ACE_Banana, 300);
        };
    };

    class I_E_CargoNet_01_ammo_F;
    class Tenthed_Resupply_Weapons : I_E_CargoNet_01_ammo_F {
        displayName = "[10th] Weapons Resupply";
        editorCategory = "Tenthed_EditorCategory_Items";
        editorSubcategory = "Tenthed_EditorSubcategory_Objects_Supplies";
        class EventHandlers {
            init = "(_this select 0) addAction ['Weapons Resupply', {}];";
        };
        class TransportMagazines {
            MAG_XX(hlc_200rnd_556x45_B_SAW, 50);
            MAG_XX(hlc_30rnd_556x45_EPR, 180);
            MAG_XX(1Rnd_Smoke_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeRed_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeGreen_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeYellow_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokePurple_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeBlue_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeOrange_Grenade_shell, 20);
            MAG_XX(ACE_HuntIR_M203, 50);
            MAG_XX(rhs_mag_M441_HE, 30);
            MAG_XX(rhs_mag_M433_HEDP, 30);
            MAG_XX(rhs_mag_M397_HET, 30);
            MAG_XX(rhs_mag_m576, 20);
            MAG_XX(rhs_mag_m4009, 20);
            MAG_XX(rhs_mag_M583A1_white, 20);
            MAG_XX(rhs_mag_m661_green, 20);
            MAG_XX(rhs_mag_m662_red, 20);
            MAG_XX(rhs_mag_M585_white_cluster, 20);
            MAG_XX(rhs_mag_M663_green_cluster, 20);
            MAG_XX(rhs_mag_M664_red_cluster, 20);
            MAG_XX(ACE_40mm_Flare_white, 20);
            MAG_XX(ACE_40mm_Flare_red, 20);
            MAG_XX(ACE_40mm_Flare_green, 20);
            MAG_XX(ACE_40mm_Flare_ir, 20);
            MAG_XX(PHEN_FSPLUS_ChemGrenade_RiotCSGasGrenade_40mm, 20);
            MAG_XX(PHEN_FSPLUS_ChemGrenade_RiotCSGasGrenade_40mm_3GL, 20);
            MAG_XX(BWA3_1Rnd_Flare_Illum, 20);
            MAG_XX(BWA3_1Rnd_Flare_Singlestar_White, 20);
            MAG_XX(BWA3_1Rnd_Flare_Singlestar_Green, 20);
            MAG_XX(BWA3_1Rnd_Flare_Singlestar_Red, 20);
            MAG_XX(BWA3_1Rnd_Flare_Multistar_White, 20);
            MAG_XX(BWA3_1Rnd_Flare_Multistar_Green, 20);
            MAG_XX(BWA3_1Rnd_Flare_Multistar_Red, 20);
            MAG_XX(rhsusf_20Rnd_762x51_m993_Mag, 70);
            MAG_XX(MRAWS_HEAT_F, 100);
            MAG_XX(rhs_fim92_mag, 100);
        };
        class TransportWeapons{
            WEAP_XX(hlc_rifle_M4_grip2, 30);
            WEAP_XX(hlc_m249_pip2_30Rnd, 15);
            WEAP_XX(rhs_weap_M320, 20);
            WEAP_XX(BWA3_P2A1, 30);
            WEAP_XX(rhs_weap_m14ebrri, 15);
            WEAP_XX(rhs_weap_maaws, 20);
            WEAP_XX(rhs_weap_M136, 40);
            WEAP_XX(rhs_weap_fim92, 20);
        };
        //class TransportBackpacks { };
        class TransportItems { };
    };

    class C_IDAP_supplyCrate_F;
    class Tenthed_Resupply_Explosives : C_IDAP_supplyCrate_F {
        displayName = "[10th] Explosives Resupply";
        editorCategory = "Tenthed_EditorCategory_Items";
        editorSubcategory = "Tenthed_EditorSubcategory_Objects_Supplies";
        class EventHandlers {
            init = "(_this select 0) addAction ['Explosives Resupply', {}];";
        };
        class TransportMagazines { };
        class TransportWeapons{ };
        //class TransportBackpacks { };
        class TransportItems {
            ITEM_XX(SmokeShell, 40);
            ITEM_XX(SmokeShellYellow, 20);
            ITEM_XX(SmokeShellGreen, 20);
            ITEM_XX(SmokeShellRed, 20);
            ITEM_XX(SmokeShellPurple, 20);
            ITEM_XX(SmokeShellOrange, 20);
            ITEM_XX(SmokeShellBlue, 20);
            ITEM_XX(rhs_mag_m67, 60);
            ITEM_XX(rhs_mag_an_m14_th3, 30);
            ITEM_XX(PHEN_FSPLUS_ChemGrenade_RiotCSGasGrenade, 30);
            ITEM_XX(ACE_HandFlare_White, 10);
            ITEM_XX(ACE_HandFlare_Red, 10);
            ITEM_XX(ACE_HandFlare_Green, 10);
            ITEM_XX(ACE_HandFlare_Yellow, 10);
            ITEM_XX(rhsusf_m112_mag, 40);
            //ITEM_XX(tsp_breach_block_mag, 30);
            //ITEM_XX(tsp_breach_package_mag, 15);
            //ITEM_XX(tsp_breach_popper_mag, 60);
            //ITEM_XX(tsp_breach_stick_mag, 15);
            ITEM_XX(SatchelCharge_Remote_Mag, 10);
        };
    };

    class C_IDAP_CargoNet_01_supplies_F;
    class Tenthed_Resupply_Medical : C_IDAP_CargoNet_01_supplies_F {
        displayName = "[10th] Medical Resupply";
        editorCategory = "Tenthed_EditorCategory_Items";
        editorSubcategory = "Tenthed_EditorSubcategory_Objects_Supplies";
        class EventHandlers {
            init = "(_this select 0) addAction ['Medical Resupply', {}];";
        };
        class TransportMagazines { };
        class TransportWeapons{ };
        //class TransportBackpacks { };
        class TransportItems {
            ITEM_XX(ACE_fieldDressing, 100);
            ITEM_XX(ACE_packingBandage, 100);
            ITEM_XX(ACE_elasticBandage, 100);
            ITEM_XX(ACE_morphine, 60);
            ITEM_XX(ACE_adenosine, 60);
            ITEM_XX(ACE_epinephrine, 100);
            ITEM_XX(ACE_plasmaIV, 15);
            ITEM_XX(ACE_plasmaIV_500, 30);
            ITEM_XX(ACE_plasmaIV_250, 20);
            ITEM_XX(ACE_bloodIV, 15);
            ITEM_XX(ACE_bloodIV_500, 30);
            ITEM_XX(ACE_bloodIV_250, 20);
            ITEM_XX(ACE_salineIV, 15);
            ITEM_XX(ACE_salineIV_500, 30);
            ITEM_XX(ACE_salineIV_250, 20);
            ITEM_XX(ACE_quikclot, 100);
            ITEM_XX(ACE_bodyBag, 40);
            ITEM_XX(ACE_painkillers_Item, 60);
            ITEM_XX(ACE_ATNAA_AntidoteInjector, 60);
            ITEM_XX(ACE_splint, 40);
        };
    };

    class B_CargoNet_01_ammo_F;
    class Tenthed_Resupply_Emergency : B_CargoNet_01_ammo_F {
        displayName = "[10th] Emergency Resupply";
        editorCategory = "Tenthed_EditorCategory_Items";
        editorSubcategory = "Tenthed_EditorSubcategory_Objects_Supplies";
        class EventHandlers {
            init = "(_this select 0) addAction ['Emergency Resupply', {}];";
        };
        class TransportMagazines {
            MAG_XX(hlc_30rnd_556x45_EPR, 150);
            MAG_XX(MRAWS_HEAT_F, 40);
            MAG_XX(hlc_20Rnd_762x51_barrier_M14, 65);
            MAG_XX(1Rnd_HE_Grenade_shell, 40);
            MAG_XX(SmokeShell, 40);
            MAG_XX(SmokeShellGreen, 20);
            MAG_XX(SmokeShellRed, 20);
            MAG_XX(SmokeShellPurple, 20);
            MAG_XX(SmokeShellBlue, 20);
            MAG_XX(rhs_mag_m67, 60);
            MAG_XX(rhsusf_m112_mag, 40);
            MAG_XX(PHEN_FSPLUS_ChemGrenade_RiotCSGasGrenade, 30);
            MAG_XX(hlc_200Rnd_762x51_B_M60E4, 40);
            MAG_XX(UGL_FlareWhite_F, 20);
            MAG_XX(UGL_FlareGreen_F, 20);
            MAG_XX(UGL_FlareRed_F, 20);
            MAG_XX(UGL_FlareYellow_F, 20);
            MAG_XX(UGL_FlareCIR_F, 20);
            MAG_XX(1Rnd_Smoke_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeRed_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeGreen_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeYellow_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokePurple_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeBlue_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeOrange_Grenade_shell, 20);
            MAG_XX(rhs_mag_rsp30_white, 20);
            MAG_XX(rhs_mag_rsp30_red, 20);
            MAG_XX(rhs_mag_rsp30_green, 20);
            MAG_XX(BWA3_1Rnd_Flare_Illum, 20);
            MAG_XX(BWA3_1Rnd_Flare_Singlestar_White, 20);
            MAG_XX(BWA3_1Rnd_Flare_Singlestar_Green, 20);
            MAG_XX(BWA3_1Rnd_Flare_Singlestar_Red, 20);
            MAG_XX(BWA3_1Rnd_Flare_Multistar_White, 20);
            MAG_XX(BWA3_1Rnd_Flare_Multistar_Green, 20);
            MAG_XX(BWA3_1Rnd_Flare_Multistar_Red, 20);
            MAG_XX(rhs_mag_an_m14_th3, 20);
            //MAG_XX(tsp_breach_block_mag, 30);
            //MAG_XX(tsp_breach_package_mag, 10);
            //MAG_XX(tsp_breach_popper_mag, 40);
            //MAG_XX(tsp_breach_stick_mag, 15);
        };
        class TransportWeapons{
            WEAP_XX(hlc_wp_M4_TacReload, 30);
            WEAP_XX(rhs_weap_maaws, 8);
            WEAP_XX(rhs_weap_m72a7, 12);
            WEAP_XX(hlc_rifle_M14dmr_Rail_TacReload, 15);
            WEAP_XX(hlc_lmg_M60E4_200rnd, 15);
            WEAP_XX(rhs_weap_M320, 15);
            WEAP_XX(BWA3_P2A1, 20);
        };
        // TODO: Fix backpacks into correct zone
        /*class TransportBackpacks {
            ITEM_XX(Tenthed_M252_Backpack, 2);
            ITEM_XX(Tenthed_M2HBM3_Backpack, 4);
            ITEM_XX(Tenthed_M41A4TOW_Backpack, 4);
        };*/
        class TransportItems {
            ITEM_XX(diw_armor_plates_main_plate, 50);
            ITEM_XX(ACE_fieldDressing, 75);
            ITEM_XX(ACE_packingBandage, 75);
            ITEM_XX(ACE_elasticBandage, 75);
            ITEM_XX(ACE_splint, 30);
            ITEM_XX(ACE_morphine, 75);
            ITEM_XX(ACE_adenosine, 50);
            ITEM_XX(ACE_epinephrine, 75);
            ITEM_XX(ACE_salineIV, 30);
            ITEM_XX(ACE_salineIV_500, 60);
            ITEM_XX(ACE_quikclot, 75);
            ITEM_XX(ACE_painkillers_Item, 75);
            ITEM_XX(ACE_ATNAA_AntidoteInjector, 50);
        };
    };

    class B_supplyCrate_F;
    class Tenthed_Resupply_Misc : B_supplyCrate_F {
        displayName = "[10th] Misc Equipment Resupply";
        editorCategory = "Tenthed_EditorCategory_Items";
        editorSubcategory = "Tenthed_EditorSubcategory_Objects_Supplies";
        class EventHandlers {
            init = "(_this select 0) addAction ['Misc Equipment Resupply', {}];";
        };
        class TransportMagazines { };
        class TransportWeapons{ };
        // TODO: Fix backpacks into correct zone
        /*class TransportBackpacks {
            ITEM_XX(Tenthed_M252_Backpack, 4);
            ITEM_XX(Tenthed_M2HBM3_Backpack, 8);
            ITEM_XX(Tenthed_M41A4TOW_Backpack, 8);
        };*/
        class TransportItems {
            //ITEM_XX(diw_armor_plates_main_plate, 60);
            ITEM_XX(ACE_IR_Strobe_Item, 60);
            ITEM_XX(ACE_CableTie, 60);
            //ITEM_XX(CBRN_gasmaskFilter, 60);
            //ITEM_XX(CBRN_sealant, 100);
            //ITEM_XX(CBRN_DuctTape, 80);
            //ITEM_XX(G_CBRN_A, 30);
        };
    };
};