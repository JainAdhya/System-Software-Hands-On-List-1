#include <stdio.h>
#include <unistd.h>

int main(){
    while(1){
        printf("Process running with PID = %d\n", getpid());
        sleep(5);  
    }
    return 0;
}


/* Output: Terminal 1
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/2$ nano infinite.c
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/2$ gcc infinite.c -o infinite
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/2$ ./infinite &
[1] 2747
Process running with PID = 2747
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/2$ Process running with PID = 2747
Process running with PID = 2747
Process running with PID = 2747
Process running with PID = 2747
Process running with PID = 2747
..........
*/

/*
Output: Terminal 2
adhya@adhya:~$ cd /proc/2747
adhya@adhya:/proc/2747$ ls
arch_status      gid_map            ns             smaps
attr             io                 numa_maps      smaps_rollup
auxv             ksm_merging_pages  oom_adj        stack
cgroup           ksm_stat           oom_score      stat
clear_refs       latency            oom_score_adj  statm
cmdline          limits             pagemap        status
comm             loginuid           patch_state    syscall
coredump_filter  map_files          personality    task
cpuset           maps               projid_map     timens_offsets
cwd              mem                root           timers
environ          mountinfo          sched          timerslack_ns
exe              mounts             schedstat      uid_map
fd               mountstats         sessionid      wchan
fdinfo           net                setgroups
*/
