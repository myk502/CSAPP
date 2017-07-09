#include<stdio.h>
#include<assert.h>

int any_odd_one(unsigned x)
/*return 1 when any odd bit of x equals to 1,0 otherwise
assume that w=32
*/
{
    unsigned mask=0xAAAAAAAA;
    return (x&mask!=0);

}

int main(void)
{
    assert(2);
    assert(0);
    return 0;
}
