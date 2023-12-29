#pragma hls_top
unsigned char minhash(unsigned short set1 [90], unsigned short set2 [90]){
    unsigned char count=0;
    #pragma hls_unroll yes
    for ( unsigned char i = 0; i<90; i++){
	    #pragma hls_unroll yes
        for ( unsigned char j = 0; j<90; j++){
            if (set1[i]==set2[j]){
                count+=1;
            }
        }
    }
    return count;
}
