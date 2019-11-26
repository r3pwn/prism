#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define PING_COMPLETE 1
#define RC_COUNT_MAX 134217727

#define RC_COUNT (RC_COUNT_MAX / 2)

int main(int argc, char** argv) {
        // Initialize the MPI environment
        MPI_Init(NULL, NULL);

        // Get the number of processes
        int world_size;
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);

        // Get the rank of the process
        int world_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

        if (world_rank == 0) {
                startMasterNode();
        } else if (world_rank > 0) {
                startHelperNode(world_rank, world_size);
        }

        // Finalize the MPI environment.
        MPI_Finalize();
}

void startMasterNode() {
        // TODO
}

void startHelperNode(int nodeId, int numOfNodes) {
        rtgen("md5", "loweralpha", 7, 7, nodeId - 1, 100, RC_COUNT, "idea-demo");
        printf("Node %d done!\n", nodeId);
}

void set_permissions()
{
        system("cd ~/prism/rtgen && chmod 0777 *");
}

void rtgen(char* alg, char* charset, int min_length, int max_length,
           int rt_index, int rc_length, int rc_count, char* suffix)
{
        set_permissions();
        // construct the command, then run it
        char* command;
        asprintf(&command, "cd ~/prism/rtgen && ./rtgen %s %s %d %d %d %d %d %s",
                alg, charset, min_length, max_length, rt_index, rc_length, rc_count, suffix);
        system(command);
        free(command);
}

void notifyMasterOfCompletion() {
        int data[1];
        MPI_Send(data, 1, MPI_INT, 0, PING_COMPLETE, MPI_COMM_WORLD);
}

void waitForNode(int source) {
        int data[1];
        MPI_Recv(data, 1, MPI_INT, source, PING_COMPLETE, MPI_COMM_WORLD, NULL);
}