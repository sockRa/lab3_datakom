#include "prog3.h"


extern int TRACE;
extern int YES;
extern int NO;
extern float clocktime;

#define INF 999
#define NODE1 1
#define NUM_OF_NODES 4

int node1ToNodes[] = {1};


struct distance_table 
{
  int costs[4][4];
} dt1;

void printdt1(struct distance_table *dtptr)

  
{
  printf("             via   \n");
  printf("   D1 |    0     2 \n");
  printf("  ----|-----------\n");
  printf("     0|  %3d   %3d\n",dtptr->costs[0][0], dtptr->costs[0][2]);
  printf("dest 2|  %3d   %3d\n",dtptr->costs[2][0], dtptr->costs[2][2]);
  printf("     3|  %3d   %3d\n",dtptr->costs[3][0], dtptr->costs[3][2]);

}

//Utiliy min function
int min(int a, int b, int c){
  int temp = (a <= b ? a : b);
  temp = (temp <= c ? temp : c);
  return temp;
}

/* students to write the following two routines, and maybe some others */


void rtinit1()
{
  printf("\nrtinit1 invoked at time %f \n",clocktime);

  //Init distance table
  for(int i = 0; i < NUM_OF_NODES; i++){
    for(int j = 0; j < NUM_OF_NODES; j++){
      if(i == j)
        dt1.costs[i][j] = node1ToNodes[i];
      else
        dt1.costs[i][j] = INF;
    }
  }

  //Printing the initial distance table
  printdt1(&dt1);

  //Make dv packet to send to neighbours
  struct rtpkt packet;

  //Set source,dest and min cost for each packet
  for(int i = 0; i < NUM_OF_NODES; i++){
    if(i != NODE1){
      packet.sourceid = NODE1;
      packet.destid = i;
      for(int j = 0; j < NUM_OF_NODES; j++)
        packet.mincost[j] = node1ToNodes[j];
    }

    tolayer2(packet);
  }
  
}


void rtupdate1(struct rtpkt *rcvdpkt)


{
  printf("\nrtupdate1 invoked at time %f\n",clocktime);
  if(rcvdpkt->destid != NODE1)
    return;
  
  int flag = 0;
  int sourceID = rcvdpkt->sourceid;
  printf("\nPacket rcvd at node 1 from node %d\n",rcvdpkt->sourceid);

  for(int j = 0; j < NUM_OF_NODES; j++){
    if(j != NODE1 || j != sourceID){
      if(dt0.costs[j][s)
    }
  }
}


void linkhandler1(int linkid, int newcost)

/* called when cost from 1 to linkid changes from current value to newcost*/
/* You can leave this routine empty if you're an undergrad. If you want */
/* to use this routine, you'll need to change the value of the LINKCHANGE */
/* constant definition in prog3.c from 0 to 1 */
	
{
}


