#include <stdio.h>
#include <string.h>

int main() {

    /* n=Banyak proses, AT=Arrival Time, WT=Waiting Time, TAT=Turnaround Time
    b=Burst Time, TotWT=Total Waiting Time, TotTA=Total Turnaround Time
    name=Nama Proses, AWT=Average Waiting Time, AvTA=Average Turnaround time*/

    int n, AT[100], b[100], i, j, tmp, WT[100], TAT[100], time[100];
    int TotWT=0, TotTA=0;
    float AvWT, AvTA;
    char name[20][20], tmpName[20];

    printf("\n\tAlgoritma CPU Scheduling FCFS \n");
    puts("");
    printf("Jumlah Proses\t= ");
    scanf("%d", &n);
    puts("");

    // Masukkan data yang diproses
    for (i=0; i<n; i++) {
        fflush(stdin);
        printf("Nama Proses\t= ");
        scanf("%s", name[i]);
        printf("Arrival time\t= ");
        scanf("%d", &AT[i]);
        printf("Burst time\t= ");
        scanf("%d", &b[i]);
        puts("");
    }

    // Urutkan data
    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            if (AT[i] > AT[j]) {

                // Tukar nama proses
                strcpy(tmpName, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tmpName);

                // Tukar arrival time
                tmp = AT[i];
                AT[i] = AT[j];
                AT[j] = tmp;

                // Tukar burst time
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;

            }
        }
    }

    time[0] = AT[0];
    puts("\n\t Tabel Proses ");
    puts("==========================================");
    printf("| no | proses\t | time arrival\t | burst |\n");
    puts("——————————————————————————————————————————");

    for (i=0; i<n; i++) {
        printf("| %2d | %s\t | \t%d\t | %d\t |\n", i+1, name[i], AT[i], b[i]);
        
        time[i+1] = time[i] + b[i]; // Menghitung waktu sekarang pada Gantt Chart (waktu sebelumnya + burst time)
        WT[i] = time[i] - AT[i];
        TAT[i] = time[i+1] - AT[i];
        TotWT += WT[i];
        TotTA += TAT[i];
    }

    puts("==========================================");
    printf("\tTotal waiting time\t= %d \n", TotWT);
    printf("\tTurn around time\t= %d \n", TotTA);
    puts("\n\t Tabel Waktu Proses ");
    puts("==================================================");
    printf("| no | proses\t | waiting time\t | turn arround\t |\n");
    puts("——————————————————————————————————————————————————");

    for (i = 0; i < n; i++)
    {
        printf("| %2d | %s\t | \t%d\t | \t%d\t |\n", i + 1, name[i], WT[i], TAT[i]);
    }

    puts("==================================================");
    // Untuk Gantt Chart
    puts("\n");
    puts("\t Gantt-Chart \n");
    for (i=0; i<n; i++) {
        printf(" %s\t ", name[i]);
    }

    puts("");
    for (i=0; i<n; i++) {
        printf("|=========");
    }

    printf("|\n");
    for (i=0; i<=n; i++) {
        printf(" %d\t ", time[i]);
    }

    printf("\ndiperoleh dari penjumlahan Burst time");
    puts("/n");
    AvWT = (float)TotWT / n;
    AvTA = (float)TotTA / n;
    printf("\tAverage Waiting Time: %f\n", AvWT);
    printf("\tAverage Turn Around Time: %f\n", AvTA);
}
