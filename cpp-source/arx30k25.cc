#pragma hls_top
unsigned short minhash(unsigned short set1 [30], unsigned short set2 [30]){
    unsigned short p = 4095;
    unsigned short const number_of_hashes = 25;
    unsigned short b [number_of_hashes] = {4499, 8187, 4308, 7596, 5473, 6065, 6913, 4355, 6997, 4879, 5770, 6450, 6767, 5533, 4338, 4417, 8042, 4875, 5070, 6207, 6607, 6860, 7173, 6764, 7595};
    unsigned short sig1 [number_of_hashes];

    #pragma hls_unroll yes
    for ( unsigned short j = 0; j<number_of_hashes; j++){
        unsigned short minhash_value = p;
	#pragma hls_unroll yes
        for ( unsigned short k = 0; k<30; k++){
            unsigned short hash = (set1[k] + b[j]) & p;
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
        for ( unsigned short k = 0; k<30; k++){
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

