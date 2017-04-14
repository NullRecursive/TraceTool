#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

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




int main (int argc, char ** argv){

	pcap_if_t ** iface;
	char *  errbuff;
	int ret = pcap_findalldevs(iface,errbuff);
	print_devices(ret,iface,errbuff);


}