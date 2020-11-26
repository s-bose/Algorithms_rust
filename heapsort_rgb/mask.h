#ifndef _MASK_H_
#define _MASK_H_

typedef enum _color
{
    R, 
    G, 
    B
} color;
 
unsigned short mask(unsigned short num, color c)
{
    unsigned short mask_b = 31;
    unsigned short mask_g = ((31 << 1) + 1) << 5;
    unsigned short mask_r = (31 << 11);
    switch(c)
    {
        case B:
            return num & mask_b; 
        case G:
            return (num & mask_g) >> 5;
        case R:
            return (num & mask_r) >> 11;
    }
}

#endif