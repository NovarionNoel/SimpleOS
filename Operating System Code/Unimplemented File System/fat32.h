//defines and macros
#define CleanBitMask     0x08000000
#define HardErrorBitMask 0x04000000
#define NUM_PARTITIONS   1
//partition and boot definitions

typedef struct {
    uint8_t jmp[3];                 // Jump instruction
    char oem_name[8];               // OEM name
    uint16_t bytes_per_sector;      // Bytes per sector
    uint8_t sectors_per_cluster;    // Sectors per cluster
    uint16_t reserved_sectors;      // Reserved sectors
    uint8_t num_fats;               // Number of FATs
    uint16_t max_root_entries = 0;  // Maximum root directory entries
    uint16_t total_sectors_16 =0;   // Total sectors (16-bit) 
    uint8_t media_descriptor;       // Media descriptor
    uint16_t sectors_per_fat = 0;   // Sectors per FAT
    uint16_t sectors_per_track;     // Sectors per track
    uint16_t num_heads;             // Number of heads
    uint32_t hidden_sectors;        // Hidden sectors
    uint32_t total_sectors_32;      // Total sectors (32-bit)
    uint32_t sectors_per_fat32;     // Sectors per FAT (FAT32)
    uint16_t flags;                 // Flags
    uint16_t fat32_version;         // FAT32 version 
    uint32_t root_cluster;          // Cluster number of root directory
    uint16_t fs_info_sector;        // Cluster number of FS Information Sector
    uint16_t backup_boot_sector;    // Backup boot sector
    uint8_t reserved[12]=0;         // Reserved (should be zeros)
    uint8_t drive_number;           // Drive number (reserved for Windows)
    uint8_t reserved1;              // Reserved (should be zero)
    uint8_t boot_signature;         // Boot signature (0x29)
    uint32_t volume_id;             // Volume ID
    char volume_label[11];          // Volume label
    char fs_type[8];                // File system type
    char boot_code[420];            // Boot code
    uint16_t boot_sector_signature = 0x55AA; // Boot sector signature (0x55AA)
    struct {
        uint8_t status;             // Status of the partition (active/bootable or not)
        uint8_t start_head;         // Starting head
        uint8_t start_sector;       // Starting sector and cylinder
        uint8_t start_cylinder;
        uint8_t partition_type;     // Type of partition
        uint8_t end_head;           // Ending head
        uint8_t end_sector;         // Ending sector and cylinder
        uint8_t end_cylinder;
        uint32_t start_sector;
        uint32_t total_sectors;  
    } partitions[NUM_PARTITIONS];
} BootSector;

//function defintions
uint32_t * cluster_location(BootSector bootDisk, int cluster_number);
uint32_t data_sector_starts(BootSector bootDisk, int cluster_number);
uint32_t first_data_sector(BootSector bootDisk);
uint32_t fetch_fat_entry (BootSector bootDisk, uint32_t cluster_number, uint32_t *fat_table);
void set_fat_entry (BootSector bootDisk, uint32_t cluster_number, uint32_t *fat_table);
BootSector create_fat32_table();