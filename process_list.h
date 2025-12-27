#ifndef PROCESS_LIST_H
#define PROCESS_LIST_H

#include <sys/types.h>

#define MAX_CMD_LEN 256

typedef enum {
    SORT_PID,
    SORT_MEM,
    SORT_CPU
} SortMode;

typedef struct {
    pid_t pid;
    uid_t uid;
    char name[64];
    char user[32];
    char command[MAX_CMD_LEN];
    char state;
    long unsigned int memory_sq;
    float cpu_usage;
    unsigned long long utime;
    unsigned long long stime;
    int ppid;
    int threads;
    int priority;
    int nice;
    char status_name[16];
} ProcessInfo;

typedef struct {
    float cpu_percent;
    unsigned long mem_total;
    unsigned long mem_used;
    unsigned long mem_free;
    unsigned long mem_available;
    unsigned long mem_cached;
    unsigned long swap_total;
    unsigned long swap_free;
    double uptime;
    double cpu_temp;
    double bat_temp;
    char hostname[64];
    char kernel[64];
    double load_avg[3];
    double disk_read_rate;
    double disk_write_rate;
    float core_percents[32];
    int core_count;
} SystemInfo;

typedef struct {
    ProcessInfo *processes;
    int count;
    int capacity;
    SortMode sort_mode;
    unsigned long long total_cpu_time;
    unsigned long long total_cpu_idle;
    unsigned long long old_disk_read_sectors;
    unsigned long long old_disk_write_sectors;
    unsigned long long core_old_totals[32];
    unsigned long long core_old_idles[32];
    char filter[256];
} ProcessList;

ProcessList* create_process_list();
void free_process_list(ProcessList *list);
void refresh_process_list(ProcessList *list, ProcessList *prev_list);
void sort_process_list(ProcessList *list);
void get_system_info(SystemInfo *info, ProcessList *list, ProcessList *prev_list);
int compare_processes(const void *a, const void *b);

#endif
