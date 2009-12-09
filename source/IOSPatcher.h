typedef struct
{
    signed_blob *certs;
    signed_blob *ticket;
    signed_blob *tmd;
    signed_blob *crl;

    u32 certs_size;
    u32 ticket_size;
    u32 tmd_size;
    u32 crl_size;

    u8 **encrypted_buffer;
    u8 **decrypted_buffer;
    u32 *buffer_size;

    u32 content_count;
} ATTRIBUTE_PACKED IOS;

void decrypt_IOS(IOS *ios);
s32 Init_IOS(IOS **ios);
void free_IOS(IOS **ios);
s32 set_content_count(IOS *ios, u32 count);
s32 Install_patched_IOS(u32 iosnr, u32 iosrevision, bool es_trucha_patch, bool es_identify_patch, bool nand_patch, u32 location, u32 newrevision);
s32 Downgrade_IOS(u32 iosversion, u32 highrevision, u32 lowrevision);
s32 install_unpatched_IOS(u32 iosversion, u32 revision);
int patch_hash_check(u8 *buf, u32 size);
int patch_identify_check(u8 *buf, u32 size);
