#pragma hls_top
unsigned short minhash(unsigned short set1 [30], unsigned short set2 [30]){
    unsigned short p = 4095;
    unsigned short const number_of_hashes = 50;
    unsigned short b [number_of_hashes] = {5675,5278,7866,7574,6665,6192,6369,6892,6525,8169,6550,4263,7500,5546,8056,4199,6056,6101,4850,5211,5803,7905,6175,7089,5175,7345,6530,8025,6298,4273,4241,5382,4225,7048,6311,8072,6520,5636,5903,4626,4330,6161,4707,7366,4987,5264,6791,7026,5196,7361};
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

