#pragma hls_top
unsigned char minhash(unsigned short set1 [200], unsigned short set2 [200]){
    unsigned char count=0;
    #pragma hls_unroll yes
    for ( unsigned char i = 0; i<99; i++){
	    #pragma hls_unroll yes
        for ( unsigned char j = 0; j<99; j++){
            if (set1[i]==set2[j]){
                count+=1;
            }
        }
    }
	
    #pragma hls_unroll yes
    for ( unsigned char i = 99; i<198; i++){
	    #pragma hls_unroll yes
        for ( unsigned char j = 0; j<99; j++){
            if (set1[i]==set2[j]){
                count+=1;
            }
        }
    }
    #pragma hls_unroll yes
    for ( unsigned char i = 99; i<198; i++){
	    #pragma hls_unroll yes
        for ( unsigned char j = 99; j<198; j++){
            if (set1[i]==set2[j]){
                count+=1;
            }
        }
    }

    #pragma hls_unroll yes
    for ( unsigned char i = 198; i<200; i++){
	    #pragma hls_unroll yes
        for ( unsigned char j = 0; j<99; j++){
            if (set1[i]==set2[j]){
                count+=1;
            }
        }
    }
    #pragma hls_unroll yes
    for ( unsigned char i = 198; i<200; i++){
	    #pragma hls_unroll yes
        for ( unsigned char j = 99; j<198; j++){
            if (set1[i]==set2[j]){
                count+=1;
            }
        }
    }
    #pragma hls_unroll yes
    for ( unsigned char i = 198; i<200; i++){
	    #pragma hls_unroll yes
        for ( unsigned char j = 198; j<200; j++){
            if (set1[i]==set2[j]){
                count+=1;
            }
        }
    }
    return count;
}
