#include "prog3.h"


extern int TRACE;
extern int YES;
extern int NO;
extern float clocktime;

#define INF 999
#define NODE0 0
#define NUM_OF_NODES 4

int node0ToNodes[] = {0, 1, 3, 7};

struct distance_table 
{
  int costs[4][4];
} dt0;

void printdt0(struct distance_table *dtptr)

  
{
  printf("                via     \n");
  printf("   D0 |    1     2    3 \n");
  printf("  ----|-----------------\n");
  printf("     1|  %3d   %3d   %3d\n",dtptr->costs[1][1],
	 dtptr->costs[1][2],dtptr->costs[1][3]);
  printf("dest 2|  %3d   %3d   %3d\n",dtptr->costs[2][1],
	 dtptr->costs[2][2],dtptr->costs[2][3]);
  printf("     3|  %3d   %3d   %3d\n",dtptr->costs[3][1],
	 dtptr->costs[3][2],dtptr->costs[3][3]);
}


//Utiliy min function
int min(int a, int b, int c){
  int temp = (a <= b ? a : b);
  temp = (temp <= c ? temp : c);
  return temp;
}

/* students to write the following two routines, and maybe some others */

void rtinit0() 
{
  printf("\nrtinit0 invoked at time %f \n",clocktime);

  //Init distance table

  for(int i = 0; i < NUM_OF_NODES; i++){
    for(int j = 0; j < NUM_OF_NODES; j++){
      if(i == j)
        dt0.costs[i][j] = node0ToNodes[i];
      else
        dt0.costs[i][j] = INF;
    }
  }

  //Printing the initial distance table
  printdt0(&dt0);

  //Make dv packet to send to neighbours
  struct rtpkt packet;

  //Set source,dest and min cost for each packet.
  for(int i = 0; i < NUM_OF_NODES; i++){
    if(i != NODE0){
      packet.sourceid = NODE0;
      packet.destid = i;
      for(int j = 0; j < NUM_OF_NODES; j++)
        packet.mincost[j] = node0ToNodes[j];
    }

    tolayer2(packet);
  }
}


void rtupdate0(struct rtpkt *rcvdpkt)
  
{
  printf("\nrtupdate0 invoked at time %f\n",clocktime);
  //Wrong destination check
  //complete this
  if(rcvdpkt->destid != NODE0)
    return;
  

  //Flag is set to 1 in case there is an update in the distance table
  int flag = 0;
  int sourceID = rcvdpkt->sourceid;
  printf("\nPacket rcvd at node 0 from node %d\n",rcvdpkt -> sourceid);

  //Traversing column j of distance table to see if it needs to be updated

  for(int j = 0; j < NUM_OF_NODES; j++){
    if(j != NODE0 || j != sourceID){
        if(dt0.costs[j][sourceID] > (rcvdpkt->mincost[j] + dt0.costs[sourceID][sourceID])){
          dt0.costs[j][sourceID] = (rcvdpkt->mincost[j] + dt0.costs[sourceID][sourceID]);
          flag = 1;
        }
    }
  }

  //Change in dt0 detected!
  if(flag == 1){
    printf("\nDistance table at node 0 updated: \n");
    printdt0(&dt0);
    
    struct rtpkt packet;

    for(int i = 0; i < NUM_OF_NODES; i++){
      if(i != NODE0){
        packet.sourceid = NODE0;
        packet.destid = i;

        //Calculate shortest path
        for(int j = 0; j < NUM_OF_NODES; j++){
          if(j != NODE0)
            packet.mincost[j] = min(dt0.costs[j][1],dt0.costs[j][2],dt0.costs[j][3]);
        }

        tolayer2(packet);
      }
    }

    //Send dv packets to neighbors
    //complete here
  }
}

void linkhandler0(int linkid, int newcost)


/* called when cost from 0 to linkid changes from current value to newcost*/
/* You can leave this routine empty if you're an undergrad. If you want */
/* to use this routine, you'll need to change the value of the LINKCHANGE */
/* constant definition in prog3.c from 0 to 1 */
	
{
}

