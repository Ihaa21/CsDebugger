
#include "registers.h"
#include "registers.cpp"

// TODO: Add FP16
// TODO: Add WaveGetLaneIndex and WaveReadLaneAt

int main(int argc, char** argv)
{
    // NOTE: Init all our masks
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        _GlobalExecMask.Data[ThreadId] = 0xFFFFFFFF;
        _GlobalReturnMask.Data[ThreadId] = 0xFFFFFFFF;
    }
    
    // NOTE: Test If
    {
        int1 ThreadId = {};
        for (int LoopId = 0; LoopId < WAVE_SIZE; ++LoopId)
        {
            ThreadId.Data[LoopId] = LoopId;
        }

        // NOTE: One if
        int4 Value1 = 1;
        int4 Value2 = 2;
        IF (ThreadId == 2)
        {
            Value1 = Value1 + Value2;
        }
        END_IF;

        int i = 0;
    }

    // NOTE: Test For
    {
        int1 ThreadId = {};
        for (int LoopId = 0; LoopId < WAVE_SIZE; ++LoopId)
        {
            ThreadId.Data[LoopId] = LoopId;
        }

        int1 Value = 0;
        FOR(int1 LoopId = 0, LoopId < ThreadId, LoopId++)
        {
            Value += 2;
        }
        END_FOR;

        int1 Value2 = 0;
        FOR(int1 LoopId = 0, LoopId < ThreadId, LoopId++)
        {
            Value2 = Value + 2;
            IF(LoopId == 2)
            {
                Value2 += 1000;
            }
            END_IF;
        }
        END_FOR;

        int1 Value3 = 0;
        FOR(int1 Y = 0, Y < 2, Y++)
        {
            FOR(int1 X = 0, X < 2, X++)
            {
                Value3++;
            }
            END_FOR;
        }
        END_FOR;
        
    }
    
    // NOTE: Test operator type combinations
    {
        // NOTE: Set to integers
        int1 Test1 = 1;
        int2 Test2 = 1;

        uint1 Test3 = 1;
        uint2 Test4 = 1;

        // NOTE: Regular typed adds
        int1 Test5 = Test1 + Test1;
        int2 Test6 = Test2 + Test2;

        uint1 Test7 = Test3 + Test3;
        uint2 Test8 = Test4 + Test4;

        // NOTE: Mixed type adds
        int1 Test9 = Test1 + Test3;
        int2 Test10 = Test2 + Test4;

        uint1 Test11 = Test1 + Test3;
        uint2 Test12 = Test2 + Test4;

        // NOTE: Vector Scalar adds
        int1 Test13 = Test1 + 1;
        int2 Test14 = Test2 + 1;

        uint1 Test15 = Test3 + 1;
        uint2 Test16 = Test4 + 1;

        // NOTE: Equating int to uint
        uint1 Test17 = Test13;
        uint2 Test18 = Test14;

        int1 Test19 = Test15;
        int2 Test20 = Test16;

        // NOTE: Adding int and int2/3/4 together
        uint2 Test21 = uint2(1, 1) + Test17;
        int2 Test22 = int2(1, 1) + Test17;
        //uint3 Test22 = uint3(1, 1, 1) + Test17;
        //uint4 Test23 = uint4(1, 1, 1, 1) + Test17;

        // NOTE: Adding int2 to all other types
        //uint1 Test25 = uint1(1) + uint2(1, 1);
        //uint2 Test25 = uint2(1, 1) + uint2(1, 1);
        //uint3 Test26 = uint3(1, 1, 1) + uint2(1, 1);
        //uint4 Test27 = uint4(1, 1, 1, 1) + uint2(1, 1);
    }
    
    return 0;
}
