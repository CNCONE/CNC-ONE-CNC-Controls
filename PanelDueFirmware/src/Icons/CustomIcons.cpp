#include "asf.h"
#include "Configuration.hpp"
#include "Icons.hpp"

extern const uint16_t CNCOne_30h[] =
{
    30, 56,            // width and height in pixels
    0x0034, 0x2965, 0x0000, 0x4a49, 0x0000, 0x8c71, 0x0000, 0xb5b6, 0x0000, 0xdedb, 0x0000, 0xef7d,
    0x0000, 0xce59, 0x0014, 0x2965, 0x0000, 0x73ae, 0x0000, 0xce59, 0x0000, 0xef5d, 0x0004, 0xffff,
    0x0000, 0xef5d, 0x0014, 0x2965, 0x0000, 0xef7d, 0x0001, 0xffff, 0x0000, 0xffdf, 0x0000, 0xdefb,
    0x0000, 0xc618, 0x0000, 0x9cd3, 0x0000, 0xffdf, 0x0000, 0xef7d, 0x0013, 0x2965, 0x0000, 0x31a6,
    0x0000, 0xffff, 0x0000, 0xf79e, 0x0000, 0x7bcf, 0x0000, 0x39c7, 0x0002, 0x2965, 0x0000, 0xf7be,
    0x0000, 0xef5d, 0x0013, 0x2965, 0x0000, 0x31a6, 0x0000, 0xffff, 0x0000, 0xe73c, 0x0004, 0x2965,
    0x0000, 0xf7be, 0x0000, 0xef7d, 0x0013, 0x2965, 0x0000, 0x3186, 0x0000, 0xffff, 0x0000, 0xe73c,
    0x0004, 0x2965, 0x0000, 0xf7be, 0x0000, 0xef7d, 0x0013, 0x2965, 0x0000, 0x31a6, 0x0000, 0xffff,
    0x0000, 0xe73c, 0x0004, 0x2965, 0x0000, 0xce59, 0x0000, 0xad55, 0x0013, 0x2965, 0x0000, 0x31a6,
    0x0000, 0xffff, 0x0000, 0xdefb, 0x0003, 0x2965, 0x0000, 0x3186, 0x0000, 0x630c, 0x0000, 0x8c51,
    0x0013, 0x2965, 0x0000, 0x3186, 0x0000, 0x6b4d, 0x0000, 0x3186, 0x0000, 0x4a69, 0x0000, 0x8c51,
    0x0000, 0xb5b6, 0x0000, 0xd6ba, 0x0000, 0xf79e, 0x0000, 0xffff, 0x0000, 0xef5d, 0x0013, 0x2965,
    0x0000, 0x3186, 0x0000, 0xce79, 0x0000, 0xef5d, 0x0003, 0xffff, 0x0000, 0xffdf, 0x0000, 0xdefb,
    0x0000, 0xb5b6, 0x0013, 0x2965, 0x0000, 0x3186, 0x0002, 0xffff, 0x0000, 0xdedb, 0x0000, 0xad55,
    0x0000, 0x73ae, 0x0000, 0x39c7, 0x0015, 0x2965, 0x0000, 0x3186, 0x0000, 0xd69a, 0x0001, 0xffff,
    0x0000, 0xffdf, 0x0000, 0xb596, 0x0000, 0x39c7, 0x0018, 0x2965, 0x0000, 0x8410, 0x0000, 0xe71c,
    0x0001, 0xffff, 0x0000, 0xef7d, 0x0000, 0x9492, 0x0018, 0x2965, 0x0000, 0x3186, 0x0000, 0x9cd3,
    0x0000, 0xef7d, 0x0001, 0xffff, 0x0000, 0xdedb, 0x0000, 0x738e, 0x0016, 0x2965, 0x0000, 0x630c,
    0x0000, 0x9cd3, 0x0000, 0xc638, 0x0000, 0xffdf, 0x0001, 0xffff, 0x0000, 0xef5d, 0x000e, 0x2965,
    0x0000, 0x2986, 0x0003, 0x2965, 0x0000, 0x3186, 0x0000, 0xd6ba, 0x0000, 0xf79e, 0x0003, 0xffff,
    0x0000, 0xf79e, 0x0000, 0xd6ba, 0x0000, 0xad75, 0x0009, 0x2965, 0x0000, 0x29c9, 0x0000, 0x2291,
    0x0000, 0x1b36, 0x0000, 0x13ba, 0x0001, 0x043e, 0x0000, 0x2315, 0x0002, 0x2965, 0x0000, 0x3186,
    0x0000, 0xffff, 0x0000, 0xffdf, 0x0000, 0xe71c, 0x0000, 0xc618, 0x0000, 0x9cf3, 0x0000, 0x632c,
    0x0000, 0x3186, 0x0006, 0x2965, 0x0000, 0x2987, 0x0000, 0x2a4f, 0x0000, 0x2315, 0x0000, 0x1b99,
    0x0000, 0x0c1d, 0x0005, 0x045f, 0x0000, 0x0c1d, 0x0002, 0x2965, 0x0000, 0x3186, 0x0000, 0x7bcf,
    0x0000, 0x39c7, 0x0000, 0x2965, 0x0000, 0x4a49, 0x0000, 0x8c51, 0x0000, 0xb5b6, 0x0000, 0xd6ba,
    0x0000, 0xef7d, 0x0000, 0xc638, 0x0001, 0x2965, 0x0000, 0x29a8, 0x0000, 0x2336, 0x0000, 0x13db,
    0x0000, 0x045e, 0x0009, 0x045f, 0x0000, 0x043e, 0x0003, 0x2965, 0x0000, 0x738e, 0x0000, 0xce59,
    0x0000, 0xe73c, 0x0004, 0xffff, 0x0000, 0xef5d, 0x0001, 0x2965, 0x0000, 0x13da, 0x0008, 0x045f,
    0x0000, 0x043e, 0x0000, 0x0c1d, 0x0001, 0x045f, 0x0000, 0x043e, 0x0003, 0x2965, 0x0000, 0xef7d,
    0x0001, 0xffff, 0x0000, 0xffdf, 0x0000, 0xe71c, 0x0000, 0xc618, 0x0000, 0x9cf3, 0x0000, 0xffdf,
    0x0000, 0xef7d, 0x0000, 0x2965, 0x0000, 0x2a0c, 0x0005, 0x045f, 0x0000, 0x13fc, 0x0000, 0x1b78,
    0x0000, 0x22d3, 0x0000, 0x2a2d, 0x0000, 0x2986, 0x0000, 0x2a2d, 0x0001, 0x045f, 0x0000, 0x043e,
    0x0002, 0x2965, 0x0000, 0x39c7, 0x0000, 0xffff, 0x0000, 0xf79e, 0x0000, 0x7bef, 0x0000, 0x31a6,
    0x0002, 0x2965, 0x0000, 0xf7be, 0x0000, 0xef7d, 0x0000, 0x2965, 0x0000, 0x2a4f, 0x0002, 0x045f,
    0x0000, 0x2336, 0x0000, 0x2a70, 0x0000, 0x29a8, 0x0002, 0x2965, 0x0000, 0x5aeb, 0x0000, 0x3186,
    0x0000, 0x2a2d, 0x0001, 0x045f, 0x0000, 0x043e, 0x0002, 0x2965, 0x0000, 0x31a6, 0x0000, 0xffff,
    0x0000, 0xe73c, 0x0004, 0x2965, 0x0000, 0xf7be, 0x0000, 0xef7d, 0x0000, 0x2965, 0x0000, 0x2a4f,
    0x0001, 0x045f, 0x0000, 0x0bfc, 0x0000, 0x2965, 0x0000, 0x39c7, 0x0000, 0x8c71, 0x0000, 0xb5b6,
    0x0000, 0xdedb, 0x0000, 0xf79e, 0x0000, 0xffff, 0x0000, 0x73ae, 0x0000, 0x2a2d, 0x0001, 0x045f,
    0x0000, 0x043e, 0x0002, 0x2965, 0x0000, 0x3186, 0x0000, 0xffff, 0x0000, 0xe73c, 0x0004, 0x2965,
    0x0000, 0xf7be, 0x0000, 0xef7d, 0x0000, 0x2965, 0x0000, 0x2a4f, 0x0001, 0x045f, 0x0000, 0x0bfc,
    0x0000, 0x2965, 0x0000, 0xbdf7, 0x0004, 0xffff, 0x0000, 0x7bcf, 0x0000, 0x2a2d, 0x0001, 0x045f,
    0x0000, 0x043e, 0x0002, 0x2965, 0x0000, 0x31a6, 0x0000, 0xffff, 0x0000, 0xe73c, 0x0004, 0x2965,
    0x0000, 0xce79, 0x0000, 0xad55, 0x0000, 0x2965, 0x0000, 0x2a4f, 0x0001, 0x045f, 0x0000, 0x0bfc,
    0x0000, 0x2965, 0x0000, 0xc638, 0x0004, 0xffff, 0x0000, 0x73ae, 0x0000, 0x2a2d, 0x0001, 0x045f,
    0x0000, 0x043e, 0x0002, 0x2965, 0x0000, 0x31a6, 0x0000, 0xffff, 0x0000, 0xe71c, 0x0007, 0x2965,
    0x0000, 0x2a4f, 0x0001, 0x045f, 0x0000, 0x0bfc, 0x0000, 0x2965, 0x0000, 0xce59, 0x0004, 0xffff,
    0x0000, 0x7bcf, 0x0000, 0x2a2d, 0x0001, 0x045f, 0x0000, 0x043e, 0x0002, 0x2965, 0x0000, 0x3186,
    0x0000, 0x6b6d, 0x0000, 0x31a6, 0x0007, 0x2965, 0x0000, 0x2a4f, 0x0001, 0x045f, 0x0000, 0x0c1c,
    0x0000, 0x2965, 0x0000, 0xc638, 0x0004, 0xffff, 0x0000, 0x7bcf, 0x0000, 0x2a2d, 0x0001, 0x045f,
    0x0000, 0x0c1c, 0x000d, 0x2965, 0x0000, 0x2a4f, 0x0001, 0x045f, 0x0000, 0x0c1c, 0x0000, 0x2965,
    0x0000, 0xc638, 0x0004, 0xffff, 0x0000, 0x7bcf, 0x0000, 0x29c9, 0x0000, 0x22d3, 0x0000, 0x2a0c,
    0x0000, 0x2986, 0x000d, 0x2965, 0x0000, 0x2a4f, 0x0001, 0x045f, 0x0000, 0x0bfc, 0x0000, 0x2965,
    0x0000, 0xc638, 0x0004, 0xffff, 0x0000, 0x7bcf, 0x0000, 0x2965, 0x0000, 0x3186, 0x0000, 0x6b4d,
    0x0000, 0x9cd3, 0x0008, 0x2965, 0x0000, 0x528a, 0x0000, 0x9492, 0x0000, 0xb5b6, 0x0000, 0x94b2,
    0x0000, 0x2965, 0x0000, 0x2a4e, 0x0000, 0x0c1c, 0x0000, 0x1b99, 0x0000, 0x22f3, 0x0000, 0x2965,
    0x0000, 0xce59, 0x0004, 0xffff, 0x0000, 0x7bcf, 0x0000, 0x632c, 0x0000, 0xf7be, 0x0000, 0xffff,
    0x0000, 0xf7be, 0x0003, 0x2965, 0x0000, 0x3186, 0x0000, 0x8410, 0x0000, 0xad75, 0x0000, 0xd69a,
    0x0000, 0xef7d, 0x0002, 0xffff, 0x0000, 0xef5d, 0x0005, 0x2965, 0x0000, 0xce59, 0x0004, 0xffff,
    0x0000, 0x632c, 0x0000, 0x6b4d, 0x0001, 0xffff, 0x0000, 0xf7be, 0x0003, 0x2965, 0x0000, 0xd69a,
    0x0003, 0xffff, 0x0000, 0xf79e, 0x0000, 0xdedb, 0x0000, 0xffdf, 0x0000, 0xef5d, 0x0000, 0x2965,
    0x0000, 0x4a69, 0x0000, 0xad55, 0x0001, 0xd69a, 0x0000, 0x2965, 0x0000, 0xc618, 0x0000, 0xffff,
    0x0000, 0xe73c, 0x0000, 0xce59, 0x0000, 0xa534, 0x0000, 0x6b4d, 0x0000, 0x2965, 0x0000, 0x6b6d,
    0x0001, 0xffff, 0x0000, 0xf7be, 0x0002, 0x2965, 0x0000, 0x3186, 0x0000, 0xffff, 0x0000, 0xffdf,
    0x0000, 0xc618, 0x0000, 0x9cf3, 0x0000, 0x630c, 0x0000, 0x3186, 0x0000, 0x2965, 0x0001, 0xef7d,
    0x0000, 0x2965, 0x0000, 0x7bef, 0x0001, 0xffff, 0x0000, 0xef5d, 0x0000, 0x2965, 0x0000, 0x4228,
    0x0000, 0x4a49, 0x0002, 0x2965, 0x0000, 0x5aeb, 0x0000, 0x9cd3, 0x0000, 0xd6ba, 0x0001, 0xffff,
    0x0000, 0xf79e, 0x0002, 0x2965, 0x0000, 0x31a6, 0x0000, 0xffff, 0x0000, 0xdefb, 0x0004, 0x2965,
    0x0001, 0xef7d, 0x0000, 0x2965, 0x0000, 0x7bef, 0x0001, 0xffff, 0x0000, 0xef5d, 0x0000, 0x2965,
    0x0000, 0x4208, 0x0000, 0x8430, 0x0000, 0xb596, 0x0000, 0xd6ba, 0x0000, 0xef7d, 0x0004, 0xffff,
    0x0000, 0xef5d, 0x0002, 0x2965, 0x0000, 0x31a6, 0x0000, 0xffff, 0x0000, 0xdedb, 0x0003, 0x2965,
    0x0000, 0x3186, 0x0000, 0xf79e, 0x0000, 0xef7d, 0x0000, 0x2965, 0x0000, 0x7bef, 0x0002, 0xffff,
    0x0000, 0xef5d, 0x0000, 0xffdf, 0x0008, 0xffff, 0x0000, 0xb596, 0x0002, 0x2965, 0x0000, 0x31a6,
    0x0000, 0xffff, 0x0000, 0xe71c, 0x0000, 0x2965, 0x0000, 0x6b6d, 0x0000, 0xa514, 0x0000, 0xce59,
    0x0000, 0xef5d, 0x0000, 0xffff, 0x0000, 0xef5d, 0x0000, 0x2965, 0x0000, 0x7bcf, 0x000a, 0xffff,
    0x0000, 0xf7be, 0x0000, 0xdedb, 0x0000, 0x9cd3, 0x0000, 0x3186, 0x0002, 0x2965, 0x0000, 0x3186,
    0x0001, 0xffff, 0x0000, 0xf7be, 0x0003, 0xffff, 0x0000, 0xffdf, 0x0000, 0xa514, 0x0000, 0x2965,
    0x0000, 0x6b4d, 0x0005, 0xffff, 0x0000, 0xffdf, 0x0000, 0xe73c, 0x0000, 0xc638, 0x0000, 0xa514,
    0x0000, 0x6b4d, 0x0000, 0x3186, 0x0006, 0x2965, 0x0000, 0xf7be, 0x0001, 0xffff, 0x0000, 0xef5d,
    0x0000, 0xce79, 0x0000, 0xad75, 0x0000, 0x7bcf, 0x0000, 0x39e7, 0x0001, 0x2965, 0x0000, 0x3186,
    0x0000, 0xd6ba, 0x0000, 0xffdf, 0x0000, 0xef5d, 0x0000, 0xd69a, 0x0000, 0xad75, 0x0000, 0x8410,
    0x0000, 0x39c7, 0x000b, 0x2965, 0x0000, 0x7bcf, 0x0000, 0x8c51, 0x0000, 0x4a69, 0x0000, 0x2965,
    0x0000, 0x39e7, 0x0000, 0x7bef, 0x0000, 0xad75, 0x0000, 0xd69a, 0x0000, 0xd6ba, 0x0014, 0x2965,
    0x0000, 0x6b6d, 0x0000, 0xa514, 0x0000, 0xc638, 0x0000, 0xe71c, 0x0000, 0xffdf, 0x0002, 0xffff,
    0x0000, 0xef5d, 0x0013, 0x2965, 0x0000, 0x31a6, 0x0003, 0xffff, 0x0000, 0xef7d, 0x0000, 0xd69a,
    0x0000, 0xb596, 0x0000, 0x8410, 0x0000, 0x39e7, 0x0013, 0x2965, 0x0000, 0x31a6, 0x0000, 0xffdf,
    0x0001, 0xffff, 0x0000, 0xd69a, 0x0000, 0x528a, 0x0018, 0x2965, 0x0000, 0x6b6d, 0x0000, 0xd6ba,
    0x0001, 0xffff, 0x0000, 0xf7be, 0x0000, 0xad55, 0x0000, 0x31a6, 0x0018, 0x2965, 0x0000, 0x8430,
    0x0000, 0xe71c, 0x0001, 0xffff, 0x0000, 0xe73c, 0x0000, 0x8430, 0x0018, 0x2965, 0x0000, 0x3186,
    0x0000, 0xad55, 0x0000, 0xffdf, 0x0001, 0xffff, 0x0000, 0xce59, 0x0014, 0x2965, 0x0000, 0x7bef,
    0x0000, 0xad55, 0x0000, 0xce79, 0x0000, 0xef5d, 0x0003, 0xffff, 0x0000, 0xe73c, 0x0013, 0x2965,
    0x0000, 0x3186, 0x0003, 0xffff, 0x0000, 0xef5d, 0x0000, 0xce59, 0x0000, 0xad55, 0x0000, 0x73ae,
    0x0000, 0x31a6, 0x0013, 0x2965, 0x0000, 0x3186, 0x0000, 0xd69a, 0x0000, 0xb596, 0x0000, 0x8c51,
    0x0000, 0x4228, 0x0000, 0x2965, 0x0000, 0x31a6, 0x0000, 0x7bcf, 0x0000, 0xad55, 0x0000, 0xbdd7,
    0x0015, 0x2965, 0x0000, 0x528a, 0x0000, 0x8430, 0x0000, 0xc618, 0x0000, 0xe71c, 0x0000, 0xffdf,
    0x0001, 0xffff, 0x0000, 0xef5d, 0x0013, 0x2965, 0x0000, 0x3186, 0x0000, 0xf79e, 0x0000, 0xdefb,
    0x0000, 0xce79, 0x0002, 0xffff, 0x0000, 0xf79e, 0x0000, 0xffff, 0x0000, 0xef5d, 0x0013, 0x2965,
    0x0000, 0x3186, 0x0000, 0xffff, 0x0000, 0xe71c, 0x0000, 0xb596, 0x0000, 0xce79, 0x0000, 0xffff,
    0x0000, 0x94b2, 0x0000, 0x2965, 0x0000, 0xf79e, 0x0000, 0xef5d, 0x0013, 0x2965, 0x0000, 0x3186,
    0x0000, 0xffff, 0x0000, 0xe71c, 0x0000, 0x2965, 0x0000, 0x7bcf, 0x0000, 0xffff, 0x0000, 0x8c51,
    0x0000, 0x2965, 0x0000, 0xf79e, 0x0000, 0xef5d, 0x0013, 0x2965, 0x0000, 0x3186, 0x0000, 0xffff,
    0x0000, 0xe71c, 0x0000, 0x2965, 0x0000, 0x7bcf, 0x0000, 0xffff, 0x0000, 0x8c51, 0x0000, 0x2965,
    0x0000, 0xf79e, 0x0000, 0xef5d, 0x0013, 0x2965, 0x0000, 0x3186, 0x0000, 0xffff, 0x0000, 0xe71c,
    0x0000, 0x2965, 0x0000, 0x6b4d, 0x0000, 0xce59, 0x0000, 0x630c, 0x0000, 0x2965, 0x0000, 0xf79e,
    0x0000, 0xef5d, 0x0013, 0x2965, 0x0000, 0x3186, 0x0000, 0xffff, 0x0000, 0xe71c, 0x0004, 0x2965,
    0x0000, 0x7bcf, 0x0000, 0x4208, 0x0013, 0x2965, 0x0000, 0x3186, 0x0000, 0xdedb, 0x0000, 0xad55,
    0x0007, 0x2965
};

extern const uint8_t IconSettings[] =
{   30, 30,   // width, height
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x11, 0x11, 0x11, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x11, 0x11, 0x11, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x13, 0x33, 0x33, 0x31, 0x11, 0x13, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x33, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11,
    0x11, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x11,
    0x11, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x11,
    0x11, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x11,
    0x11, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x11,
    0x11, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x11,
    0x11, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x11,
    0x11, 0x11, 0x33, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x13, 0x33, 0x33, 0x31, 0x11, 0x13, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x11, 0x11, 0x11, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x11, 0x11, 0x11, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
};

extern const uint8_t IconConsole[] =
{   30, 30,   // width, height
	    0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x33, 0x11, 0x11, 0x11, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x33, 0x31, 0x11, 0x13, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x33, 0x33, 0x11, 0x33, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x33, 0x33, 0x33, 0x33, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x33, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x33, 0x33, 0x33, 0x11, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x13, 0x33, 0x31, 0x11, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x31, 0x11, 0x11, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x13, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x33, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x33, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x33, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x33, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x33, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x33, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x33, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x13, 0x31, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11,
	    0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11,
};
