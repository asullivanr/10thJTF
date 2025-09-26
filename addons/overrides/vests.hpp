	class ItemCore;
	class H_HelmetB: ItemCore
	{
		class ItemInfo;
	};
	class VestItem;
	class TEN_Ballistic_Mask: H_HelmetB
	{
		author="GanX";
		displayName="TEN - Ballistic Mask";
		picture="\GX_BLANCO_CARTEL\Textures\Icons\GX_Ballistic_Mask.paa";
		model="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask.p3d";
		class ItemInfo: ItemInfo
		{
			mass=20;
			uniformModel="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask.p3d";
			modelSides[]={3,2,1,0};
			class HitpointsProtectionInfo
			{
				class head
				{
					hitpointName="HitHead";
					armor=6;
					passThrough=0.5;
					explosionShielding=6;
				};
			};
		};
	};
	class TEN_B_M_Good: TEN_Ballistic_Mask
	{
		author="GanX";
		displayName="TEN - Ballistic Mask (Good)";
		picture="\GX_BLANCO_CARTEL\Textures\Icons\GX_Ballistic_Mask.paa";
		model="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask.p3d";
		class ItemInfo: ItemInfo
		{
			mass=20;
			uniformModel="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask.p3d";
			modelSides[]={3,2,1,0};
			class HitpointsProtectionInfo
			{
				class head
				{
					hitpointName="HitHead";
					armor=10;
					passThrough=0.40000001;
					explosionShielding=10;
				};
			};
		};
	};
	class TEN_B_M_Extreme: TEN_Ballistic_Mask
	{
		author="GanX";
		displayName="TEN - Ballistic Mask (Extreme)";
		picture="\GX_BLANCO_CARTEL\Textures\Icons\GX_Ballistic_Mask.paa";
		model="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask.p3d";
		class ItemInfo: ItemInfo
		{
			mass=20;
			uniformModel="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask.p3d";
			modelSides[]={3,2,1,0};
			class HitpointsProtectionInfo
			{
				class head
				{
					hitpointName="HitHead";
					armor=20;
					passThrough=0.30000001;
					explosionShielding=20;
				};
			};
		};
	};
	class TEN_B_M_God: TEN_Ballistic_Mask
	{
		author="GanX";
		displayName="TEN - Ballistic Mask (God)";
		picture="\GX_BLANCO_CARTEL\Textures\Icons\GX_Ballistic_Mask.paa";
		model="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask.p3d";
		class ItemInfo: ItemInfo
		{
			mass=20;
			uniformModel="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask.p3d";
			modelSides[]={3,2,1,0};
			class HitpointsProtectionInfo
			{
				class head
				{
					hitpointName="HitHead";
					armor=100;
					passThrough=0;
					explosionShielding=100;
				};
			};
		};
	};
	class TEN_B_M_Officer: TEN_Ballistic_Mask
	{
		author="GanX";
		displayName="TEN - Ballistic Mask Officer";
		picture="\GX_BLANCO_CARTEL\Textures\Icons\GX_Ballistic_Mask.paa";
		model="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask_Officer.p3d";
		class ItemInfo: ItemInfo
		{
			mass=20;
			uniformModel="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask_Officer.p3d";
			modelSides[]={3,2,1,0};
			class HitpointsProtectionInfo
			{
				class head
				{
					hitpointName="HitHead";
					armor=20;
					passThrough=0.30000001;
					explosionShielding=20;
				};
			};
		};
	};
	class TEN_B_M_SL: TEN_Ballistic_Mask
	{
		author="GanX";
		displayName="TEN - Ballistic Mask Squad Leader";
		picture="\GX_BLANCO_CARTEL\Textures\Icons\GX_Ballistic_Mask.paa";
		model="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask_SL.p3d";
		class ItemInfo: ItemInfo
		{
			mass=20;
			uniformModel="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask_SL.p3d";
			modelSides[]={3,2,1,0};
			class HitpointsProtectionInfo
			{
				class head
				{
					hitpointName="HitHead";
					armor=20;
					passThrough=0.30000001;
					explosionShielding=20;
				};
			};
		};
	};
	class TEN_B_M_Up: TEN_Ballistic_Mask
	{
		author="GanX";
		displayName="TEN - Ballistic Mask Up";
		picture="\GX_BLANCO_CARTEL\Textures\Icons\GX_Ballistic_Mask.paa";
		model="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask_Up.p3d";
		class ItemInfo: ItemInfo
		{
			mass=20;
			uniformModel="\GX_BLANCO_CARTEL\Models\GX_Ballistic_Mask_Up.p3d";
			modelSides[]={3,2,1,0};
			class HitpointsProtectionInfo
			{
				class head
				{
					hitpointName="HitHead";
					armor=0;
					passThrough=1;
					explosionShielding=0;
				};
			};
		};
	};
	class V_PlateCarrier1_blk;
	class V_PlateCarrierGL_blk;
	class V_PlateCarrierSpec_blk;
	class TEN_BC_Carrier_GL_Black: V_PlateCarrierGL_blk
	{
		author="GanX";
		displayName="TEN - BC Carrier GL Rig (Black)";
		picture="\A3\Characters_F_Mark\Data\UI\icon_carrier_gl_rig_mtp.paa";
		model = "\A3\Characters_F\BLUFOR\equip_b_vest02.p3d";
		hiddenSelectionsTextures[]=
		{
			"\GX_BLANCO_CARTEL\Textures\Vests\GX_B_C_Carrier_GL_Rig_Black.paa"
		};
		class ItemInfo: VestItem {
            uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest02.p3d";
            containerClass = "Supply140";
            mass = 100;
            class HitpointsProtectionInfo
            {
                class Abdomen   { hitpointName = "HitAbdomen";   armor = 16; passThrough = 0.3; };
                class Arms      { hitpointName = "HitArms";      armor = 8;  passThrough = 0.4; };
                class Chest     { hitpointName = "HitChest";     armor = 50; passThrough = 0.4; };
                class Diaphragm { hitpointName = "HitDiaphragm"; armor = 50; passThrough = 0.4; };
                class Neck      { hitpointName = "HitNeck";      armor = 8;  passThrough = 0.4; };
                class Pelvis    { hitpointName = "HitPelvis";    armor = 16; passThrough = 0.3; };
            };
        };
	};
	class TEN_BC_Carrier_Special_Black: V_PlateCarrierSpec_blk
	{
		author="GanX";
		displayName="TEN - BC Carrier Special Rig (Black)";
		picture="\A3\Characters_F_Mark\Data\UI\icon_carrier_spec_rig_mtp.paa";
		model = "\A3\Characters_F\BLUFOR\equip_b_vest02.p3d";
		hiddenSelectionsTextures[]=
		{
			"\GX_BLANCO_CARTEL\Textures\Vests\GX_B_C_Carrier_GL_Rig_Black.paa"
		};
		class ItemInfo: VestItem {
            uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest02.p3d";
            containerClass = "Supply140";
            mass = 100;
            class HitpointsProtectionInfo
            {
                class Abdomen   { hitpointName = "HitAbdomen";   armor = 16; passThrough = 0.3; };
                class Arms      { hitpointName = "HitArms";      armor = 8;  passThrough = 0.4; };
                class Chest     { hitpointName = "HitChest";     armor = 50; passThrough = 0.4; };
                class Diaphragm { hitpointName = "HitDiaphragm"; armor = 50; passThrough = 0.4; };
                class Neck      { hitpointName = "HitNeck";      armor = 8;  passThrough = 0.4; };
                class Pelvis    { hitpointName = "HitPelvis";    armor = 16; passThrough = 0.3; };
            };
        };
	};
	class Weapon_Base_F;
	class arifle_CTARS_blk_F;
	class srifle_DMR_04_F;
	class TEN_arifle_CTARS_blk_F: arifle_CTARS_blk_F
	{
		author="$STR_A3_Bohemia_Interactive";
		_generalMacro="arifle_CTARS_blk_F";
		class LinkedItems
		{
			class linkedItemsAcc
			{
				slot="PointerSlot";
				item="acc_pointer_IR";
			};
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_Hamr";
			};
		};
	};
	class TEN_srifle_DMR_04_F: srifle_DMR_04_F
	{
		author="$STR_A3_Bohemia_Interactive";
		_generalMacro="srifle_DMR_04_F";
		class LinkedItems
		{
			class linkedItemsAcc
			{
				slot="PointerSlot";
				item="acc_pointer_IR";
			};
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_AMS";
			};
			class LinkedItemsUnder
			{
				slot="UnderBarrelSlot";
				item="bipod_02_F_blk";
			};
		};
	};
	class UniformItem;
	class U_C_FormalSuit_01_tshirt_gray_F;
	class U_I_G_resistanceLeader_F;
	class TEN_U_C_FormalSuit_01_tshirt_gray_F: U_C_FormalSuit_01_tshirt_gray_F
	{
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"\a3\Characters_F_AoW\Uniforms\Suitpacks\data\suitpack_FormalSuit_01_tshirt_Gray_CO.paa"
		};
		modelSides[]={0};
		scope=1;
		class ItemInfo: UniformItem
		{
			uniformClass="TEN_B_C_Miguel_Blanco";
			containerClass="Supply20";
			mass=30;
			modelSides[]={0};
		};
	};
	class TEN_U_I_G_resistanceLeader_F: U_I_G_resistanceLeader_F
	{
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"\a3\Characters_F_AoW\Uniforms\Suitpacks\data\suitpack_FormalSuit_01_tshirt_Gray_CO.paa"
		};
		modelSides[]={0};
		scope=1;
		class ItemInfo: UniformItem
		{
			uniformClass="TEN_B_C_Javier_Blanco";
			containerClass="Supply40";
			mass=40;
			modelSides[]={0};
		};
	};