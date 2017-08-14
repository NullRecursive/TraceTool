
/*
*Para executar o programa precisa esta logado como root


*/
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define SIZEMAX 2048




void print_devices(int ret,  pcap_if_t**iface, char * errbuff){

	if(ret == -1){
		printf("%s\n", errbuff);
		return;
	}

	if(ret == 0){
		printf("%s\n","-----------------Devices availables-----------------" );

		for (pcap_if_t* it = *iface; it != NULL ; it = it->next){
			printf("%s\n",it->name);
			(it->description == NULL) ? printf("%s\n\n", ""): printf("%s\n\n", it->description);
		}
	}
}

void show_help(){
	
	printf("%s\n","No parameters" );
	printf("%s\n","usage:  ./tracetool.out  [options] [param]");
	printf("%s\n", "options: \n -li: \t\t list Devices availables\n -h \t\t print help\n  -c: \t\t capture traffic network with device especidied in [param]" );

}

void listen_print(pcap_t* handle){
	printf("%s\n", handle->);
}


int main (int argc, char *argv[]){


	if(argc <= 1){
		show_help();
		return 1;
	}
	// Processes terminal commands
		if(!strcmp( (*(argv+1)),"-li")){
			pcap_if_t ** iface;
			char *  errbuff;
			int ret = pcap_findalldevs(iface,errbuff);
			print_devices(ret,iface,errbuff);
			pcap_freealldevs(*iface);

			return 0;
		}
		if(!strcmp( (*(argv+1)),"-h")){
			show_help();
		}
		if(!strcmp((*(argv+1)),"-c")){

			// open  a packet handle in promiscuous mode
			open capture device
			pcap_t* handle;
			char *  errbuff;
			handle  =  pcap_open_live((*(argv+1)), MAXSIZE, 1, 1000, errbuf);
		

			if(handle == NULL){
				fprintf(stderr, "Couldn't open device %s\n",(*(argv+1)) );
			}



}
