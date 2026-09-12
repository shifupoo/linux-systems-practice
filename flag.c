#include <stdio.h>
#include <stdlib.h>

#define DEVICE_ENABLED  (1u << 0)
#define DEVICE_ERROR    (1u << 1)
#define DEVICE_BUSY     (1u << 2)
#define DEVICE_INTERRUPT_ENABLED (1u << 3)


void set_flag(unsigned int *flags, unsigned int mask) {
    *flags |= mask;
}
void clear_flag(unsigned int *flags, unsigned int mask) {
    *flags &= ~mask;
}
int is_flag_set(unsigned int flags, unsigned int mask) {
    return (flags & mask);
}

int count_bit_set(unsigned int flags) {
    int count = 0;

    while(flags != 0) {
        flags &= (flags - 1);
        count++;
    }
    return count;
}
void check_multiple2(unsigned int flags){
    if(flags & 1u) 
        printf("is multiple of 2\n");
    else
        printf("is not multpitle of 2 \n");
}

void check_power_of_two(unsigned int flags) {
    if(flags != 0 && ( flags & (flags -1) == 0)) {
        printf("Is power of two \n");
    }else{
        printf("Is not power of two \n");
    }
}
int main() {

    unsigned int flags = 0;

    //enable device
    set_flag(&flags, DEVICE_ENABLED);

    //enable interrupts
    set_flag(&flags, DEVICE_INTERRUPT_ENABLED);
    
    //verifică dacă device este enabled
    if(is_flag_set(flags,DEVICE_ENABLED))
        printf("The divice is enable \n");
    else
        printf("The divice is not enable \n");
    //setează ERROR
    set_flag(&flags, DEVICE_ERROR);
    //șterge ERROR
    clear_flag(&flags, DEVICE_ERROR); 
    //setează BUSY 
    set_flag(&flags, DEVICE_BUSY);
    //afișează valoarea finală a lui flags
    printf("flags = %u \n", flags);

    check_power_of_two(flags);
    printf("count the bits that are set %d \n", count_bit_set(flags));
    return 0;
}