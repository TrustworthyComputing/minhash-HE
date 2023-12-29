#pragma hls_top
unsigned char minhash(unsigned short set1 [30], unsigned short set2 [30]){
    unsigned char count=0;
    #pragma hls_unroll yes
    for ( unsigned char i = 0; i<30; i++){
	    #pragma hls_unroll yes
        for ( unsigned char j = 0; j<30; j++){
            if (set1[i]==set2[j]){
                count+=1;
            }
        }
    }
    return count;
}
