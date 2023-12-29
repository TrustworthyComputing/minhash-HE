#pragma hls_top
unsigned short minhash(unsigned short set1 [10], unsigned short set2 [10]){
    unsigned short p = 4095;
    unsigned short const number_of_hashes = 5;
    unsigned short b [number_of_hashes] = {4679,5262,5608,5774,7994};
    unsigned short sig1 [number_of_hashes];

    #pragma hls_unroll yes
    for ( unsigned short j = 0; j<number_of_hashes; j++){
        unsigned short minhash_value = p;
	#pragma hls_unroll yes
        for ( unsigned short k = 0; k<10; k++){
            unsigned short hash = (set1[k] + b[j]) & p;
	    if (set1[k]==0){
		break;
	    }
            if (hash < minhash_value){
                minhash_value = hash;
            }
        }
        sig1[j] = minhash_value;

    }

    unsigned short sig2[number_of_hashes];
    #pragma hls_unroll yes
    for ( unsigned short j = 0; j<number_of_hashes; j++){
        unsigned short minhash_value = p;
        #pragma hls_unroll yes
        for ( unsigned short k = 0; k<10; k++){
            unsigned short hash = (set2[k] + b[j]) & p;
            if (hash < minhash_value){
                minhash_value = hash;
            }
        }
        sig2[j] = minhash_value;

    }

    unsigned short count=0;
    #pragma hls_unroll yes
    for( unsigned short i = 0; i < number_of_hashes; i++){
        if (sig1[i] == sig2[i]){
            count+=1;
        }
    }
    return count;
}

