if(HEMTT.is_release())
{
    print("pre_build: is_release=true, deleting specified files");
    HEMTT_VFS.join("addons").join("weapons").join("BruteGrenade").remove_file();

    HEMTT_VFS.join("addons").join("functions").join("ArcherMissile").remove_file();
    //HEMTT_VFS.join("addons").join("functions").join("functions").remove_file();
}
else if(HEMTT.is_build())
{
    print("pre_build: is_build=true, keeping files");
}else if(HEMTT.is_dev())
{
    print("pre_build: is_dev=true, building for dev");
}