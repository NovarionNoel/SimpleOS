#include <math.h>
#include "fat32.h"


uint32_t first_data_sector(BootSector bootDisk){
    //number of root sectors in fat32 always zero
    return (bootDisk.reserved_sectors+ (bootDisk.num_fats*bootDisk.total_sectors_32)+0);
}

uint32_t data_sector_starts(BootSector bootDisk, int cluster_number){
    return (((cluster_number-2)*bootDisk.sectors_per_cluster)+first_data_sector(bootDisk));
}

uint32_t * cluster_location(BootSector bootDisk, int cluster_number){
    int fat_offset= cluster_number*4;
    uint32_t fat_sector_number=bootDisk.reserved_sectors+(fat_offset/bootDisk.bytes_per_sector);
    uint32_t curr_offset= fat_offset%bootDisk.bytes_per_sector;
    uint32_t *result = (uint32_t *)malloc(2 * sizeof(uint32_t));
    
    result[0] = fat_sector_number;
    result[1] = curr_offset;
    return result;
}

uint32_t fetch_fat_entry (BootSector bootDisk, uint32_t cluster_number, uint32_t *fat_table){
    uint32_t *location=cluster_location(bootDisk, cluster_number);
    uint32_t fat_sector_number=location[0];
    uint32_t fat_sector_offset=location[1];
    free(location);
    uint32_t fat_entry = fat_table[fat_sector_offset / sizeof(uint32_t)] & 0x0FFFFFFF; 
    return fat_entry;
}

void set_fat_entry(BootSector bootDisk, uint32_t *fat_table, uint32_t cluster_number, uint32_t value){
    uint32_t *location=cluster_location(bootDisk,cluster_number);
    uint32_t fat_sector_number=location[0];
    uint32_t fat_sector_offset=location[1];
    free(location);
    fat_table[fat_sector_offset / sizeof(uint32_t)] |= (value & 0x0FFFFFFF);
}

BootSector create_fat32_table(){
    uint64_t drive_size_bytes = 64 * 1073741824;
    uint32_t total_sectors_32 = (uint32_t)(drive_size_bytes / 512);
    uint32_t sectors_per_fat32= (total_sectors_32/8)*4/512;
    BootSector mbr;
    memset(&mbr,0,sizeof(BootSector));
    
    mbr.jmp = {0xEB, 0x3C, 0x90};
    mbr.oem_name = "RCVF2";
    mbr.bytes_per_sector = 512;
    mbr.sectors_per_cluster= 8;
    mbr.reserved_sectors=32;
    mbr.num_fats=2;
    mbr.media_descriptor = 0xF8;
    mbr.sectors_per_track = 63;
    mbr.num_heads = 255,
    mbr.hidden_sectors = 0,
    mbr.total_sectors_32=total_sectors_32;
    mbr.sectors_per_fat32=sectors_per_fat32;
    mbr.flags=0;
    mbr.fat32_version=0;
    mbr.root_cluster=2;
    mbr.fs_info_sector=1;
    mbr.backup_boot_sector=6;
    mbr.reserved= {0};
    mbr.drive_number=0x80;
    mbr.reserved1=0;
    mbr.boot_signature=0x29;
    mbr.volume_id=0xACEF2222;
    mbr.volume_label="BASE";
    mbr.fs_type="FAT32";
    mbr.boot_code={0};
    mbr.partitions[0].status = 0x80; 
    mbr.partitions[0].partition_type = 0x0C; // FAT32 partition type
    mbr.partitions[0].start_head = 0x00; 
    mbr.partitions[0].start_sector = 0x02;
    mbr.partitions[0].start_cylinder = 0x00;
    mbr.partitions[0].end_head = 0xFF; 
    mbr.partitions[0].end_sector = 0xFF; 
    mbr.partitions[0].end_cylinder = 0xFF;
    mbr.partitions[0].start_sector = 0x00000001; 
    mbr.partitions[0].total_sectors = 0xFFFFFFFF; 
    
}