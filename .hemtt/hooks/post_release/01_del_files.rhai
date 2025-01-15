print("Post_Release: deleting specified pbos and bisign files");
let release_addons = HEMTT_RFS.join(".hemttout").join("release").join("addons");

let addons_to_remove = ["Tenthed_objects.pbo", "Tenthed_supplies.pbo", "Tenthed_Armor_Base.pbo", "Tenthed_Armor_Named.pbo", "Tenthed_Helmets_Named.pbo"]; // which files to remove
for removelist in addons_to_remove {
    release_addons.join(removelist).remove_file();
    release_addons.join(removelist + "." + HEMTT.project().prefix() + "_" + HEMTT.project().version().to_string() + ".bisign").remove_file();
    print("Removed addon: " + removelist);
}
