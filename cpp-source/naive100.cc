#pragma hls_top
unsigned char minhash(unsigned short set1 [100], unsigned short set2 [100]){
    unsigned char count=0;
    #pragma hls_unroll yes
    for ( unsigned char i = 0; i<99; i++){
	    #pragma hls_unroll yes
        for ( unsigned char j = 0; j<99; j++){
            if (set1[i]==set2[j]){
                count+=1;
            }
        }
	if (set1[i]==set2[99]){
	    count+=1;
	}
    }
    #pragma hls_unroll yes
    for (unsigned char j =0; j<99; j++){
	if (set1[99]==set2[j]){
	    count+=1;
	}
    }
    if (set1[99]==set2[99]){
	count+=1;
    }
    return count;
}
