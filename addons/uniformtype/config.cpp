class CfgPatches {
    class z_tenthed_uniformtype {
        author = "Akira";
		requiredAddons[]=
		{
			"A3_Data_F",
			"A3_Weapons_F"
		};
        units[] = {};
        weapons[] = {};
    };
};

class CfgWeapons
{
	class InventoryItem_Base_F;
	class ItemCore;
	class U_BasicBody;
	class UniformItem: InventoryItem_Base_F
	{
		type=801;
		uniformType="Neopren";
	};
	class Uniform_Base: ItemCore
	{
		scope=0;
		allowedSlots[]={901};
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="B_Soldier_F";
			containerClass="Supply0";
			uniformType="Neopren";
			mass=0;
		};
	};
};
