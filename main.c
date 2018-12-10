#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
#include <errno.h>

int main(){
	char ans[256];
	int MID = shmget(9000,256,0664 | IPC_CREAT);
	char * block = shmat(MID,NULL,0);

	if(strlen(block) != 0){
	printf("Block: %s\n", block);
	}
	
	else{
	printf("Just created\n");
	}

	printf("Ya want to edit/delete the block?(edit/delete/exit)\n");
	fgets(ans,256,stdin);
	//IDK WHY THERES A NEW LINE CAUSED SO MANY PROBLEMS>>>
	ans[strlen(ans) - 1] = 0;

	//printf("ANSWER:%s\n",ans);
	
	if(strcmp(ans,"edit") == 0){
		printf("type a word to change it to!");
		fgets(ans,256,stdin);
		ans[strlen(ans) - 1] = 0;
		printf("Writing:%s\n",ans);

		strcpy(block,ans);
		printf("New block:%s\n",block);
		}
	else if(strcmp(ans,"delete") == 0){
		shmctl(MID, IPC_RMID, NULL);
		//exit(0);
		}
	
	else{
		shmdt(block);
		}
		
	return 0;

}
	
	