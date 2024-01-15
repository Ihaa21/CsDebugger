 
//=========================================================================================================================================
// NOTE: Exec Mask Functions
//=========================================================================================================================================

int ExecMaskApply(int A, int ThreadId)
{
    uint ReInterpretedBits = *(uint*)&A;
    uint MaskedBits = ReInterpretedBits & _GlobalExecMask.Data[ThreadId];
    int Result = *(int*)&MaskedBits;

    return Result;
}

uint ExecMaskApply(uint A, int ThreadId)
{
    uint Result = A & _GlobalExecMask.Data[ThreadId];
    return Result;
}

float ExecMaskApply(float A, int ThreadId)
{
    uint ReInterpretedBits = *(uint*)&A;
    uint MaskedBits = ReInterpretedBits & _GlobalExecMask.Data[ThreadId];
    int Result = *(float*)&MaskedBits;

    return Result;
}

int ExecMaskSelect(int A, int B, int ThreadId)
{
    uint ReInterpretedBitsA = *(uint*)&A;
    uint ReInterpretedBitsB = *(uint*)&B;
    uint MaskedBits = (ReInterpretedBitsA & _GlobalExecMask.Data[ThreadId]) | (ReInterpretedBitsB & (~_GlobalExecMask.Data[ThreadId]));
    int Result = *(int*)&MaskedBits;

    return Result;
}

uint ExecMaskSelect(uint A, uint B, int ThreadId)
{
    uint Result = (A & _GlobalExecMask.Data[ThreadId]) | (B & (~_GlobalExecMask.Data[ThreadId]));
    return Result;
}

float ExecMaskSelect(float A, float B, int ThreadId)
{
    uint ReInterpretedBitsA = *(uint*)&A;
    uint ReInterpretedBitsB = *(uint*)&B;
    uint MaskedBits = (ReInterpretedBitsA & _GlobalExecMask.Data[ThreadId]) | (ReInterpretedBitsB & (~_GlobalExecMask.Data[ThreadId]));
    int Result = *(float*)&MaskedBits;

    return Result;
}

//=========================================================================================================================================
// NOTE: Int1 Inits
//=========================================================================================================================================

int1::int1()
{
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = 0;
    }
}

int1::int1(const int& A)
{
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskApply(A, ThreadId);
    }
}

int1::int1(const uint& A)
{
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskApply(A, ThreadId);
    }
}

int1::int1(const uint1& A)
{
    for (uint ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskApply(A.Data[ThreadId], ThreadId);
    }
}

int1& int1::operator=(const int1& A)
{
    for (uint ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskSelect(A.Data[ThreadId], Data[ThreadId], ThreadId);
    }

    return *this;
}

//=========================================================================================================================================
// NOTE: Int2 Inits
//=========================================================================================================================================

int2::int2()
{
    x = {};
    y = {};
}

int2::int2(const int& A)
{
    x = A;
    y = A;
}

int2::int2(const uint& A)
{
    x = A;
    y = A;
}

int2::int2(const int1& A)
{
    x = A;
    y = A;
}

int2::int2(const uint1& A)
{
    x = A;
    y = A;
}

int2::int2(const uint2& A)
{
    x = A.x;
    y = A.y;
}

int2::int2(int X, int Y)
{
    x = X;
    y = Y;
}

int2& int2::operator=(const int2& A)
{
    x = A.x;
    y = A.y;
    return *this;
}

//=========================================================================================================================================
// NOTE: Int3 Inits
//=========================================================================================================================================

int3::int3()
{
    x = {};
    y = {};
    z = {};
}

int3::int3(const int& A)
{
    x = A;
    y = A;
    z = A;
}

int3::int3(const uint& A)
{
    x = A;
    y = A;
    z = A;
}

int3::int3(const int1& A)
{
    x = A;
    y = A;
    z = A;
}

int3::int3(const uint1& A)
{
    x = A;
    y = A;
    z = A;
}

int3::int3(const uint3& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
}

int3::int3(int X, int Y, int Z)
{
    x = X;
    y = Y;
    z = Z;
}

int3::int3(int2 XY, int Z)
{
    xy = XY;
    z = Z;
}

int3::int3(int1 X, int2 YZ)
{
    x = X;
    yz = YZ;
}

int3& int3::operator=(const int3& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
    return *this;
}

//=========================================================================================================================================
// NOTE: Int4 Inits
//=========================================================================================================================================

int4::int4()
{
    x = {};
    y = {};
    z = {};
    w = {};
}

int4::int4(const int& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

int4::int4(const uint& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

int4::int4(const int1& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

int4::int4(const uint1& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

int4::int4(const uint4& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
    w = A.w;
}

int4::int4(int X, int Y, int Z, int W)
{
    x = X;
    y = Y;
    z = Z;
    w = W;
}

int4::int4(int2 XY, int2 ZW)
{
    xy = XY;
    zw = ZW;
}

int4::int4(int3 XYZ, int1 W)
{
    xyz = XYZ;
    w = W;
}

int4::int4(int1 X, int3 YZW)
{
    x = X;
    yzw = YZW;
}

int4& int4::operator=(const int4& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
    w = A.w;
    return *this;
}

//=========================================================================================================================================
// NOTE: UInt1 Inits
//=========================================================================================================================================

uint1::uint1()
{
    for (uint ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = 0;
    }
}

uint1::uint1(const int& A)
{
    for (uint ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskApply(A, ThreadId);
    }
}

uint1::uint1(const uint& A)
{
    for (uint ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskApply(A, ThreadId);
    }
}

uint1::uint1(const int1& A)
{
    for (uint ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskApply(A.Data[ThreadId], ThreadId);
    }
}

uint1& uint1::operator=(const uint1& A)
{
    for (uint ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskSelect(A.Data[ThreadId], Data[ThreadId], ThreadId);
    }

    return *this;
}

//=========================================================================================================================================
// NOTE: UInt2 Inits
//=========================================================================================================================================

uint2::uint2()
{
    x = {};
    y = {};
}

uint2::uint2(const int& A)
{
    x = A;
    y = A;
}

uint2::uint2(const uint& A)
{
    x = A;
    y = A;
}

uint2::uint2(const int1& A)
{
    x = A;
    y = A;
}

uint2::uint2(const uint1& A)
{
    x = A;
    y = A;
}

uint2::uint2(const int2& A)
{
    x = A.x;
    y = A.y;
}

uint2::uint2(uint X, uint Y)
{
    x = X;
    y = Y;
}

uint2& uint2::operator=(const uint2& A)
{
    x = A.x;
    y = A.y;
    return *this;
}

//=========================================================================================================================================
// NOTE: UInt3 Inits
//=========================================================================================================================================

uint3::uint3()
{
    x = {};
    y = {};
    z = {};
}

uint3::uint3(const int& A)
{
    x = A;
    y = A;
    z = A;
}

uint3::uint3(const uint& A)
{
    x = A;
    y = A;
    z = A;
}

uint3::uint3(const int1& A)
{
    x = A;
    y = A;
    z = A;
}

uint3::uint3(const uint1& A)
{
    x = A;
    y = A;
    z = A;
}

uint3::uint3(const int3& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
}

uint3::uint3(uint X, uint Y, uint Z)
{
    x = X;
    y = Y;
    z = Z;
}

uint3::uint3(uint2 XY, uint Z)
{
    xy = XY;
    z = Z;
}

uint3::uint3(uint1 X, uint2 YZ)
{
    x = X;
    yz = YZ;
}

uint3& uint3::operator=(const uint3& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
    return *this;
}

//=========================================================================================================================================
// NOTE: UInt4 Inits
//=========================================================================================================================================

uint4::uint4()
{
    x = {};
    y = {};
    z = {};
    w = {};
}

uint4::uint4(const int& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

uint4::uint4(const uint& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

uint4::uint4(const int1& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

uint4::uint4(const uint1& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

uint4::uint4(const int4& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
    w = A.w;
}

uint4::uint4(uint X, uint Y, uint Z, uint W)
{
    x = X;
    y = Y;
    z = Z;
    w = W;
}

uint4::uint4(uint2 XY, uint2 ZW)
{
    xy = XY;
    zw = ZW;
}

uint4::uint4(uint3 XYZ, uint1 W)
{
    xyz = XYZ;
    w = W;
}

uint4::uint4(uint1 X, uint3 YZW)
{
    x = X;
    yzw = YZW;
}

uint4& uint4::operator=(const uint4& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
    w = A.w;
    return *this;
}

//=========================================================================================================================================
// NOTE: Float1 Inits
//=========================================================================================================================================

float1::float1()
{
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = 0;
    }
}

float1::float1(const int& A)
{
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskApply(A, ThreadId);
    }
}

float1::float1(const uint& A)
{
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskApply(A, ThreadId);
    }
}

float1::float1(const float& A)
{
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskApply(A, ThreadId);
    }
}

float1::float1(const int1& A)
{
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskApply(A.Data[ThreadId], ThreadId);
    }
}

float1::float1(const uint1& A)
{
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskApply(A.Data[ThreadId], ThreadId);
    }
}

float1& float1::operator=(const float1& A)
{
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Data[ThreadId] = ExecMaskSelect(A.Data[ThreadId], Data[ThreadId], ThreadId);
    }

    return *this;
}

//=========================================================================================================================================
// NOTE: Float2 Inits
//=========================================================================================================================================

float2::float2()
{
    x = {};
    y = {};
}

float2::float2(const int& A)
{
    x = A;
    y = A;
}

float2::float2(const uint& A)
{
    x = A;
    y = A;
}

float2::float2(const float& A)
{
    x = A;
    y = A;
}

float2::float2(const int1& A)
{
    x = A;
    y = A;
}

float2::float2(const uint1& A)
{
    x = A;
    y = A;
}

float2::float2(const float1& A)
{
    x = A;
    y = A;
}

float2::float2(const int2& A)
{
    x = A.x;
    y = A.y;
}

float2::float2(const uint2& A)
{
    x = A.x;
    y = A.y;
}

float2::float2(float X, float Y)
{
    x = X;
    y = Y;
}

float2& float2::operator=(const float2& A)
{
    x = A.x;
    y = A.y;
    return *this;
}

//=========================================================================================================================================
// NOTE: Float3 Inits
//=========================================================================================================================================

float3::float3()
{
    x = {};
    y = {};
    z = {};
}

float3::float3(const int& A)
{
    x = A;
    y = A;
    z = A;
}

float3::float3(const uint& A)
{
    x = A;
    y = A;
    z = A;
}

float3::float3(const float& A)
{
    x = A;
    y = A;
    z = A;
}

float3::float3(const int1& A)
{
    x = A;
    y = A;
    z = A;
}

float3::float3(const uint1& A)
{
    x = A;
    y = A;
    z = A;
}

float3::float3(const float1& A)
{
    x = A;
    y = A;
    z = A;
}

float3::float3(const int3& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
}

float3::float3(const uint3& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
}

float3::float3(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}

float3::float3(float2 XY, float Z)
{
    xy = XY;
    z = Z;
}

float3::float3(float1 X, float2 YZ)
{
    x = X;
    yz = YZ;
}

float3& float3::operator=(const float3& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
    return *this;
}

//=========================================================================================================================================
// NOTE: Float4 Inits
//=========================================================================================================================================

float4::float4()
{
    x = {};
    y = {};
    z = {};
    w = {};
}

float4::float4(const int& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

float4::float4(const uint& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

float4::float4(const float& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

float4::float4(const int1& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

float4::float4(const uint1& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

float4::float4(const float1& A)
{
    x = A;
    y = A;
    z = A;
    w = A;
}

float4::float4(const int4& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
    w = A.w;
}

float4::float4(const uint4& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
    w = A.w;
}

float4::float4(float X, float Y, float Z, float W)
{
    x = X;
    y = Y;
    z = Z;
    w = W;
}

float4::float4(float2 XY, float2 ZW)
{
    xy = XY;
    zw = ZW;
}

float4::float4(float3 XYZ, float1 W)
{
    xyz = XYZ;
    w = W;
}

float4::float4(float1 X, float3 YZW)
{
    x = X;
    yzw = YZW;
}

float4& float4::operator=(const float4& A)
{
    x = A.x;
    y = A.y;
    z = A.z;
    w = A.w;
    return *this;
}

//=========================================================================================================================================
// NOTE: General 1 Op Operator
//=========================================================================================================================================

#define MACRO_INCREMENT(Operator1, Operator2, ArgType1) \
    ArgType1& ArgType1::operator##Operator1()           \
    {                                                   \
        *this = *this Operator2 1;                      \
        return *this;                                   \
    }                                                   \
                                                        \
    ArgType1 ArgType1::operator##Operator1(int)         \
    {                                                   \
        ArgType1 Result(*this);                         \
        operator++();                                   \
        return Result;                                  \
    }

#define MACRO_UNARY(Operator1, ArgType1)            \
    ArgType1 ArgType1::operator##Operator1() const  \
    {                                               \
        return 0 - *this;                           \
    }

#define GENERATE_INCREMENT_PERMUTATION(Operator1, Operator2)    \
    MACRO_INCREMENT(Operator1, Operator2, int1);             \
    MACRO_INCREMENT(Operator1, Operator2, int2);             \
    MACRO_INCREMENT(Operator1, Operator2, int3);             \
    MACRO_INCREMENT(Operator1, Operator2, int4);             \
    MACRO_INCREMENT(Operator1, Operator2, uint1);            \
    MACRO_INCREMENT(Operator1, Operator2, uint2);            \
    MACRO_INCREMENT(Operator1, Operator2, uint3);            \
    MACRO_INCREMENT(Operator1, Operator2, uint4);            \
    MACRO_INCREMENT(Operator1, Operator2, float1);           \
    MACRO_INCREMENT(Operator1, Operator2, float2);           \
    MACRO_INCREMENT(Operator1, Operator2, float3);           \
    MACRO_INCREMENT(Operator1, Operator2, float4);           \

#define GENERATE_UNARY_PERMUTATION(Operator)    \
    MACRO_UNARY(Operator, int1);                \
    MACRO_UNARY(Operator, int2);                \
    MACRO_UNARY(Operator, int3);                \
    MACRO_UNARY(Operator, int4);                \
    MACRO_UNARY(Operator, uint1);               \
    MACRO_UNARY(Operator, uint2);               \
    MACRO_UNARY(Operator, uint3);               \
    MACRO_UNARY(Operator, uint4);               \
    MACRO_UNARY(Operator, float1);              \
    MACRO_UNARY(Operator, float2);              \
    MACRO_UNARY(Operator, float3);              \
    MACRO_UNARY(Operator, float4);              \

//=========================================================================================================================================
// NOTE: General 2 Op Operator
//=========================================================================================================================================

#define MACRO_OP2(Operator, ReturnType, ArgType1, ArgType2, AccessA, AccessB) \
    ReturnType operator##Operator(ArgType1 A, ArgType2 B)               \
    {                                                                   \
        ReturnType Result = {};                                         \
        for (int DimensionId = 0; DimensionId < ReturnType::Size(); ++DimensionId) \
        {                                                               \
            for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)    \
            {                                                           \
                auto Scalar0 = AccessA;                                 \
                auto Scalar1 = AccessB;                                 \
                Result[DimensionId].Data[ThreadId] = Scalar0 Operator Scalar1; \
            }                                                           \
        }                                                               \
                                                                        \
        return Result;                                                  \
    }

#define VECTOR_VECTOR_ADD(Operator, ReturnType, ArgType1, ArgType2) MACRO_OP2(Operator, ReturnType, ArgType1, ArgType2, A[DimensionId].Data[ThreadId], B[DimensionId].Data[ThreadId])
#define VECTOR_SCALAR_ADD(Operator, ReturnType, ArgType1, ArgType2) MACRO_OP2(Operator, ReturnType, ArgType1, ArgType2, A[DimensionId].Data[ThreadId], B)
#define SCALAR_VECTOR_ADD(Operator, ReturnType, ArgType1, ArgType2) MACRO_OP2(Operator, ReturnType, ArgType1, ArgType2, A, B[DimensionId].Data[ThreadId])
#define VECTOR1_VECTOR_ADD(Operator, ReturnType, ArgType1, ArgType2) MACRO_OP2(Operator, ReturnType, ArgType1, ArgType2, A.Data[ThreadId], B[DimensionId].Data[ThreadId])
#define VECTOR_VECTOR1_ADD(Operator, ReturnType, ArgType1, ArgType2) MACRO_OP2(Operator, ReturnType, ArgType1, ArgType2, A[DimensionId].Data[ThreadId], B.Data[ThreadId])

#define GENERATE_OP2_PERMUTATION(Operator)                  \
    VECTOR_VECTOR_ADD(Operator, int1, int1, int1);          \
    VECTOR_VECTOR_ADD(Operator, uint1, uint1, uint1);       \
    VECTOR_VECTOR_ADD(Operator, float1, float1, float1);    \
    VECTOR_VECTOR_ADD(Operator, int1, int1, uint1);         \
    VECTOR_VECTOR_ADD(Operator, int1, uint1, int1);         \
    VECTOR_VECTOR_ADD(Operator, float1, float1, uint1);     \
    VECTOR_VECTOR_ADD(Operator, float1, float1, int1);      \
    VECTOR_VECTOR_ADD(Operator, float1, uint1, float1);     \
    VECTOR_VECTOR_ADD(Operator, float1, int1, float1);      \
                                                            \
    VECTOR_VECTOR_ADD(Operator, int2, int2, int2);          \
    VECTOR_VECTOR_ADD(Operator, uint2, uint2, uint2);       \
    VECTOR_VECTOR_ADD(Operator, float2, float2, float2);    \
    VECTOR_VECTOR_ADD(Operator, int2, int2, uint2);         \
    VECTOR_VECTOR_ADD(Operator, int2, uint2, int2);         \
    VECTOR_VECTOR_ADD(Operator, float2, float2, uint2);     \
    VECTOR_VECTOR_ADD(Operator, float2, float2, int2);      \
    VECTOR_VECTOR_ADD(Operator, float2, uint2, float2);     \
    VECTOR_VECTOR_ADD(Operator, float2, int2, float2);      \
                                                            \
    VECTOR_VECTOR_ADD(Operator, int3, int3, int3);          \
    VECTOR_VECTOR_ADD(Operator, uint3, uint3, uint3);       \
    VECTOR_VECTOR_ADD(Operator, float3, float3, float3);    \
    VECTOR_VECTOR_ADD(Operator, int3, int3, uint3);         \
    VECTOR_VECTOR_ADD(Operator, int3, uint3, int3);         \
    VECTOR_VECTOR_ADD(Operator, float3, float3, uint3);     \
    VECTOR_VECTOR_ADD(Operator, float3, float3, int3);      \
    VECTOR_VECTOR_ADD(Operator, float3, uint3, float3);     \
    VECTOR_VECTOR_ADD(Operator, float3, int3, float3);      \
                                                            \
    VECTOR_VECTOR_ADD(Operator, int4, int4, int4);          \
    VECTOR_VECTOR_ADD(Operator, uint4, uint4, uint4);       \
    VECTOR_VECTOR_ADD(Operator, float4, float4, float4);    \
    VECTOR_VECTOR_ADD(Operator, int4, int4, uint4);         \
    VECTOR_VECTOR_ADD(Operator, int4, uint4, int4);         \
    VECTOR_VECTOR_ADD(Operator, float4, float4, uint4);     \
    VECTOR_VECTOR_ADD(Operator, float4, float4, int4);      \
    VECTOR_VECTOR_ADD(Operator, float4, uint4, float4);     \
    VECTOR_VECTOR_ADD(Operator, float4, int4, float4);      \
                                                            \
    VECTOR_SCALAR_ADD(Operator, int1, int1, int);           \
    VECTOR_SCALAR_ADD(Operator, uint1, uint1, uint);        \
    VECTOR_SCALAR_ADD(Operator, float1, float1, float);     \
    VECTOR_SCALAR_ADD(Operator, int1, int1, uint);          \
    VECTOR_SCALAR_ADD(Operator, int1, uint1, int);          \
    VECTOR_SCALAR_ADD(Operator, float1, float1, int);       \
    VECTOR_SCALAR_ADD(Operator, float1, float1, uint);      \
    VECTOR_SCALAR_ADD(Operator, float1, int1, float);       \
    VECTOR_SCALAR_ADD(Operator, float1, uint1, float);      \
                                                            \
    VECTOR_SCALAR_ADD(Operator, int2, int2, int);           \
    VECTOR_SCALAR_ADD(Operator, uint2, uint2, uint);        \
    VECTOR_SCALAR_ADD(Operator, float2, float2, float);     \
    VECTOR_SCALAR_ADD(Operator, int2, int2, uint);          \
    VECTOR_SCALAR_ADD(Operator, int2, uint2, int);          \
    VECTOR_SCALAR_ADD(Operator, float2, float2, int);       \
    VECTOR_SCALAR_ADD(Operator, float2, float2, uint);      \
    VECTOR_SCALAR_ADD(Operator, float2, int2, float);       \
    VECTOR_SCALAR_ADD(Operator, float2, uint2, float);      \
                                                            \
    VECTOR_SCALAR_ADD(Operator, int3, int3, int);           \
    VECTOR_SCALAR_ADD(Operator, uint3, uint3, uint);        \
    VECTOR_SCALAR_ADD(Operator, float3, float3, float);     \
    VECTOR_SCALAR_ADD(Operator, int3, int3, uint);          \
    VECTOR_SCALAR_ADD(Operator, int3, uint3, int);          \
    VECTOR_SCALAR_ADD(Operator, float3, float3, int);       \
    VECTOR_SCALAR_ADD(Operator, float3, float3, uint);      \
    VECTOR_SCALAR_ADD(Operator, float3, int3, float);       \
    VECTOR_SCALAR_ADD(Operator, float3, uint3, float);      \
                                                            \
    VECTOR_SCALAR_ADD(Operator, int4, int4, int);           \
    VECTOR_SCALAR_ADD(Operator, uint4, uint4, uint);        \
    VECTOR_SCALAR_ADD(Operator, float4, float4, float);     \
    VECTOR_SCALAR_ADD(Operator, int4, int4, uint);          \
    VECTOR_SCALAR_ADD(Operator, int4, uint4, int);          \
    VECTOR_SCALAR_ADD(Operator, float4, float4, int);       \
    VECTOR_SCALAR_ADD(Operator, float4, float4, uint);      \
    VECTOR_SCALAR_ADD(Operator, float4, int4, float);       \
    VECTOR_SCALAR_ADD(Operator, float4, uint4, float);      \
                                                            \
    SCALAR_VECTOR_ADD(Operator, int1, int, int1);           \
    SCALAR_VECTOR_ADD(Operator, uint1, uint, uint1);        \
    SCALAR_VECTOR_ADD(Operator, float1, float, float1);     \
    SCALAR_VECTOR_ADD(Operator, int1, int, uint1);          \
    SCALAR_VECTOR_ADD(Operator, int1, uint, int1);          \
    SCALAR_VECTOR_ADD(Operator, float1, float, int1);       \
    SCALAR_VECTOR_ADD(Operator, float1, float, uint1);      \
    SCALAR_VECTOR_ADD(Operator, float1, int, float1);       \
    SCALAR_VECTOR_ADD(Operator, float1, uint, float1);      \
                                                            \
    SCALAR_VECTOR_ADD(Operator, int2, int, int2);           \
    SCALAR_VECTOR_ADD(Operator, uint2, uint, uint2);        \
    SCALAR_VECTOR_ADD(Operator, int2, int, uint2);          \
    SCALAR_VECTOR_ADD(Operator, int2, uint, int2);          \
    SCALAR_VECTOR_ADD(Operator, float2, float, int2);       \
    SCALAR_VECTOR_ADD(Operator, float2, float, uint2);      \
    SCALAR_VECTOR_ADD(Operator, float2, float, float2);     \
    SCALAR_VECTOR_ADD(Operator, float2, int, float2);       \
    SCALAR_VECTOR_ADD(Operator, float2, uint, float2);      \
                                                            \
    SCALAR_VECTOR_ADD(Operator, int3, int, int3);           \
    SCALAR_VECTOR_ADD(Operator, uint3, uint, uint3);        \
    SCALAR_VECTOR_ADD(Operator, int3, int, uint3);          \
    SCALAR_VECTOR_ADD(Operator, int3, uint, int3);          \
    SCALAR_VECTOR_ADD(Operator, float3, float, int3);       \
    SCALAR_VECTOR_ADD(Operator, float3, float, uint3);      \
    SCALAR_VECTOR_ADD(Operator, float3, float, float3);     \
    SCALAR_VECTOR_ADD(Operator, float3, int, float3);       \
    SCALAR_VECTOR_ADD(Operator, float3, uint, float3);      \
                                                            \
    SCALAR_VECTOR_ADD(Operator, int4, int, int4);           \
    SCALAR_VECTOR_ADD(Operator, uint4, uint, uint4);        \
    SCALAR_VECTOR_ADD(Operator, int4, int, uint4);          \
    SCALAR_VECTOR_ADD(Operator, int4, uint, int4);          \
    SCALAR_VECTOR_ADD(Operator, float4, float, int4);       \
    SCALAR_VECTOR_ADD(Operator, float4, float, uint4);      \
    SCALAR_VECTOR_ADD(Operator, float4, float, float4);     \
    SCALAR_VECTOR_ADD(Operator, float4, int, float4);       \
    SCALAR_VECTOR_ADD(Operator, float4, uint, float4);      \
                                                            \
    VECTOR1_VECTOR_ADD(Operator, int2, int1, int2);         \
    VECTOR1_VECTOR_ADD(Operator, uint2, uint1, uint2);      \
    VECTOR1_VECTOR_ADD(Operator, int2, int1, uint2);        \
    VECTOR1_VECTOR_ADD(Operator, int2, uint1, int2);        \
    VECTOR1_VECTOR_ADD(Operator, float2, float1, int2);     \
    VECTOR1_VECTOR_ADD(Operator, float2, float1, uint2);    \
    VECTOR1_VECTOR_ADD(Operator, float2, float1, float2);   \
    VECTOR1_VECTOR_ADD(Operator, float2, int1, float2);     \
    VECTOR1_VECTOR_ADD(Operator, float2, uint1, float2);    \
                                                            \
    VECTOR1_VECTOR_ADD(Operator, int3, int1, int3);         \
    VECTOR1_VECTOR_ADD(Operator, uint3, uint1, uint3);      \
    VECTOR1_VECTOR_ADD(Operator, int3, int1, uint3);        \
    VECTOR1_VECTOR_ADD(Operator, int3, uint1, int3);        \
    VECTOR1_VECTOR_ADD(Operator, float3, float1, int3);     \
    VECTOR1_VECTOR_ADD(Operator, float3, float1, uint3);    \
    VECTOR1_VECTOR_ADD(Operator, float3, float1, float3);   \
    VECTOR1_VECTOR_ADD(Operator, float3, int1, float3);     \
    VECTOR1_VECTOR_ADD(Operator, float3, uint1, float3);    \
                                                            \
    VECTOR1_VECTOR_ADD(Operator, int4, int1, int4);         \
    VECTOR1_VECTOR_ADD(Operator, uint4, uint1, uint4);      \
    VECTOR1_VECTOR_ADD(Operator, int4, int1, uint4);        \
    VECTOR1_VECTOR_ADD(Operator, int4, uint1, int4);        \
    VECTOR1_VECTOR_ADD(Operator, float4, float1, int4);     \
    VECTOR1_VECTOR_ADD(Operator, float4, float1, uint4);    \
    VECTOR1_VECTOR_ADD(Operator, float4, float1, float4);   \
    VECTOR1_VECTOR_ADD(Operator, float4, int1, float4);     \
    VECTOR1_VECTOR_ADD(Operator, float4, uint1, float4);    \
                                                            \
    VECTOR_VECTOR1_ADD(Operator, int2, int2, int1);         \
    VECTOR_VECTOR1_ADD(Operator, uint2, uint2, uint1);      \
    VECTOR_VECTOR1_ADD(Operator, int2, int2, uint1);        \
    VECTOR_VECTOR1_ADD(Operator, int2, uint2, int1);        \
    VECTOR_VECTOR1_ADD(Operator, float2, float2, int1);     \
    VECTOR_VECTOR1_ADD(Operator, float2, float2, uint1);    \
    VECTOR_VECTOR1_ADD(Operator, float2, float2, float1);   \
    VECTOR_VECTOR1_ADD(Operator, float2, int2, float1);     \
    VECTOR_VECTOR1_ADD(Operator, float2, uint2, float1);    \
                                                            \
    VECTOR_VECTOR1_ADD(Operator, int3, int3, int1);         \
    VECTOR_VECTOR1_ADD(Operator, uint3, uint3, uint1);      \
    VECTOR_VECTOR1_ADD(Operator, int3, int3, uint1);        \
    VECTOR_VECTOR1_ADD(Operator, int3, uint3, int1);        \
    VECTOR_VECTOR1_ADD(Operator, float3, float3, int1);     \
    VECTOR_VECTOR1_ADD(Operator, float3, float3, uint1);    \
    VECTOR_VECTOR1_ADD(Operator, float3, float3, float1);   \
    VECTOR_VECTOR1_ADD(Operator, float3, int3, float1);     \
    VECTOR_VECTOR1_ADD(Operator, float3, uint3, float1);    \
                                                            \
    VECTOR_VECTOR1_ADD(Operator, int4, int4, int1);         \
    VECTOR_VECTOR1_ADD(Operator, uint4, uint4, uint1);      \
    VECTOR_VECTOR1_ADD(Operator, int4, int4, uint1);        \
    VECTOR_VECTOR1_ADD(Operator, int4, uint4, int1);        \
    VECTOR_VECTOR1_ADD(Operator, float4, float4, int1);     \
    VECTOR_VECTOR1_ADD(Operator, float4, float4, uint1);    \
    VECTOR_VECTOR1_ADD(Operator, float4, float4, float1);   \
    VECTOR_VECTOR1_ADD(Operator, float4, int4, float1);     \
    VECTOR_VECTOR1_ADD(Operator, float4, uint4, float1);    \

#define GENERATE_OP2_PERMUTATION_NO_FLOAT_RETURN(Operator)  \
    VECTOR_VECTOR_ADD(Operator, uint1, int1, int1);         \
    VECTOR_VECTOR_ADD(Operator, uint1, uint1, uint1);       \
    VECTOR_VECTOR_ADD(Operator, uint1, float1, float1);     \
    VECTOR_VECTOR_ADD(Operator, uint1, int1, uint1);        \
    VECTOR_VECTOR_ADD(Operator, uint1, uint1, int1);        \
    VECTOR_VECTOR_ADD(Operator, uint1, float1, uint1);      \
    VECTOR_VECTOR_ADD(Operator, uint1, float1, int1);       \
    VECTOR_VECTOR_ADD(Operator, uint1, uint1, float1);      \
    VECTOR_VECTOR_ADD(Operator, uint1, int1, float1);       \
                                                            \
    VECTOR_VECTOR_ADD(Operator, uint2, int2, int2);         \
    VECTOR_VECTOR_ADD(Operator, uint2, uint2, uint2);       \
    VECTOR_VECTOR_ADD(Operator, uint2, float2, float2);     \
    VECTOR_VECTOR_ADD(Operator, uint2, int2, uint2);        \
    VECTOR_VECTOR_ADD(Operator, uint2, uint2, int2);        \
    VECTOR_VECTOR_ADD(Operator, uint2, float2, uint2);      \
    VECTOR_VECTOR_ADD(Operator, uint2, float2, int2);       \
    VECTOR_VECTOR_ADD(Operator, uint2, uint2, float2);      \
    VECTOR_VECTOR_ADD(Operator, uint2, int2, float2);       \
                                                            \
    VECTOR_VECTOR_ADD(Operator, uint3, int3, int3);         \
    VECTOR_VECTOR_ADD(Operator, uint3, uint3, uint3);       \
    VECTOR_VECTOR_ADD(Operator, uint3, float3, float3);     \
    VECTOR_VECTOR_ADD(Operator, uint3, int3, uint3);        \
    VECTOR_VECTOR_ADD(Operator, uint3, uint3, int3);        \
    VECTOR_VECTOR_ADD(Operator, uint3, float3, uint3);      \
    VECTOR_VECTOR_ADD(Operator, uint3, float3, int3);       \
    VECTOR_VECTOR_ADD(Operator, uint3, uint3, float3);      \
    VECTOR_VECTOR_ADD(Operator, uint3, int3, float3);       \
                                                            \
    VECTOR_VECTOR_ADD(Operator, uint4, int4, int4);         \
    VECTOR_VECTOR_ADD(Operator, uint4, uint4, uint4);       \
    VECTOR_VECTOR_ADD(Operator, uint4, float4, float4);     \
    VECTOR_VECTOR_ADD(Operator, uint4, int4, uint4);        \
    VECTOR_VECTOR_ADD(Operator, uint4, uint4, int4);        \
    VECTOR_VECTOR_ADD(Operator, uint4, float4, uint4);      \
    VECTOR_VECTOR_ADD(Operator, uint4, float4, int4);       \
    VECTOR_VECTOR_ADD(Operator, uint4, uint4, float4);      \
    VECTOR_VECTOR_ADD(Operator, uint4, int4, float4);       \
                                                            \
    VECTOR_SCALAR_ADD(Operator, uint1, int1, int);          \
    VECTOR_SCALAR_ADD(Operator, uint1, uint1, uint);        \
    VECTOR_SCALAR_ADD(Operator, uint1, float1, float);      \
    VECTOR_SCALAR_ADD(Operator, uint1, int1, uint);         \
    VECTOR_SCALAR_ADD(Operator, uint1, uint1, int);         \
    VECTOR_SCALAR_ADD(Operator, uint1, float1, int);        \
    VECTOR_SCALAR_ADD(Operator, uint1, float1, uint);       \
    VECTOR_SCALAR_ADD(Operator, uint1, int1, float);        \
    VECTOR_SCALAR_ADD(Operator, uint1, uint1, float);       \
                                                            \
    VECTOR_SCALAR_ADD(Operator, uint2, int2, int);          \
    VECTOR_SCALAR_ADD(Operator, uint2, uint2, uint);        \
    VECTOR_SCALAR_ADD(Operator, uint2, float2, float);      \
    VECTOR_SCALAR_ADD(Operator, uint2, int2, uint);         \
    VECTOR_SCALAR_ADD(Operator, uint2, uint2, int);         \
    VECTOR_SCALAR_ADD(Operator, uint2, float2, int);        \
    VECTOR_SCALAR_ADD(Operator, uint2, float2, uint);       \
    VECTOR_SCALAR_ADD(Operator, uint2, int2, float);        \
    VECTOR_SCALAR_ADD(Operator, uint2, uint2, float);       \
                                                            \
    VECTOR_SCALAR_ADD(Operator, uint3, int3, int);          \
    VECTOR_SCALAR_ADD(Operator, uint3, uint3, uint);        \
    VECTOR_SCALAR_ADD(Operator, uint3, float3, float);      \
    VECTOR_SCALAR_ADD(Operator, uint3, int3, uint);         \
    VECTOR_SCALAR_ADD(Operator, uint3, uint3, int);         \
    VECTOR_SCALAR_ADD(Operator, uint3, float3, int);        \
    VECTOR_SCALAR_ADD(Operator, uint3, float3, uint);       \
    VECTOR_SCALAR_ADD(Operator, uint3, int3, float);        \
    VECTOR_SCALAR_ADD(Operator, uint3, uint3, float);       \
                                                            \
    VECTOR_SCALAR_ADD(Operator, uint4, int4, int);          \
    VECTOR_SCALAR_ADD(Operator, uint4, uint4, uint);        \
    VECTOR_SCALAR_ADD(Operator, uint4, float4, float);      \
    VECTOR_SCALAR_ADD(Operator, uint4, int4, uint);         \
    VECTOR_SCALAR_ADD(Operator, uint4, uint4, int);         \
    VECTOR_SCALAR_ADD(Operator, uint4, float4, int);        \
    VECTOR_SCALAR_ADD(Operator, uint4, float4, uint);       \
    VECTOR_SCALAR_ADD(Operator, uint4, int4, float);        \
    VECTOR_SCALAR_ADD(Operator, uint4, uint4, float);       \
                                                            \
    SCALAR_VECTOR_ADD(Operator, uint1, int, int1);          \
    SCALAR_VECTOR_ADD(Operator, uint1, uint, uint1);        \
    SCALAR_VECTOR_ADD(Operator, uint1, float, float1);      \
    SCALAR_VECTOR_ADD(Operator, uint1, int, uint1);         \
    SCALAR_VECTOR_ADD(Operator, uint1, uint, int1);         \
    SCALAR_VECTOR_ADD(Operator, uint1, float, int1);        \
    SCALAR_VECTOR_ADD(Operator, uint1, float, uint1);       \
    SCALAR_VECTOR_ADD(Operator, uint1, int, float1);        \
    SCALAR_VECTOR_ADD(Operator, uint1, uint, float1);       \
                                                            \
    SCALAR_VECTOR_ADD(Operator, uint2, int, int2);          \
    SCALAR_VECTOR_ADD(Operator, uint2, uint, uint2);        \
    SCALAR_VECTOR_ADD(Operator, uint2, int, uint2);         \
    SCALAR_VECTOR_ADD(Operator, uint2, uint, int2);         \
    SCALAR_VECTOR_ADD(Operator, uint2, float, int2);        \
    SCALAR_VECTOR_ADD(Operator, uint2, float, uint2);       \
    SCALAR_VECTOR_ADD(Operator, uint2, float, float2);      \
    SCALAR_VECTOR_ADD(Operator, uint2, int, float2);        \
    SCALAR_VECTOR_ADD(Operator, uint2, uint, float2);       \
                                                            \
    SCALAR_VECTOR_ADD(Operator, uint3, int, int3);          \
    SCALAR_VECTOR_ADD(Operator, uint3, uint, uint3);        \
    SCALAR_VECTOR_ADD(Operator, uint3, int, uint3);         \
    SCALAR_VECTOR_ADD(Operator, uint3, uint, int3);         \
    SCALAR_VECTOR_ADD(Operator, uint3, float, int3);        \
    SCALAR_VECTOR_ADD(Operator, uint3, float, uint3);       \
    SCALAR_VECTOR_ADD(Operator, uint3, float, float3);      \
    SCALAR_VECTOR_ADD(Operator, uint3, int, float3);        \
    SCALAR_VECTOR_ADD(Operator, uint3, uint, float3);       \
                                                            \
    SCALAR_VECTOR_ADD(Operator, uint4, int, int4);          \
    SCALAR_VECTOR_ADD(Operator, uint4, uint, uint4);        \
    SCALAR_VECTOR_ADD(Operator, uint4, int, uint4);         \
    SCALAR_VECTOR_ADD(Operator, uint4, uint, int4);         \
    SCALAR_VECTOR_ADD(Operator, uint4, float, int4);        \
    SCALAR_VECTOR_ADD(Operator, uint4, float, uint4);       \
    SCALAR_VECTOR_ADD(Operator, uint4, float, float4);      \
    SCALAR_VECTOR_ADD(Operator, uint4, int, float4);        \
    SCALAR_VECTOR_ADD(Operator, uint4, uint, float4);       \
                                                            \
    VECTOR1_VECTOR_ADD(Operator, uint2, int1, int2);        \
    VECTOR1_VECTOR_ADD(Operator, uint2, uint1, uint2);      \
    VECTOR1_VECTOR_ADD(Operator, uint2, int1, uint2);       \
    VECTOR1_VECTOR_ADD(Operator, uint2, uint1, int2);       \
    VECTOR1_VECTOR_ADD(Operator, uint2, float1, int2);      \
    VECTOR1_VECTOR_ADD(Operator, uint2, float1, uint2);     \
    VECTOR1_VECTOR_ADD(Operator, uint2, float1, float2);    \
    VECTOR1_VECTOR_ADD(Operator, uint2, int1, float2);      \
    VECTOR1_VECTOR_ADD(Operator, uint2, uint1, float2);     \
                                                            \
    VECTOR1_VECTOR_ADD(Operator, uint3, int1, int3);        \
    VECTOR1_VECTOR_ADD(Operator, uint3, uint1, uint3);      \
    VECTOR1_VECTOR_ADD(Operator, uint3, int1, uint3);       \
    VECTOR1_VECTOR_ADD(Operator, uint3, uint1, int3);       \
    VECTOR1_VECTOR_ADD(Operator, uint3, float1, int3);      \
    VECTOR1_VECTOR_ADD(Operator, uint3, float1, uint3);     \
    VECTOR1_VECTOR_ADD(Operator, uint3, float1, float3);    \
    VECTOR1_VECTOR_ADD(Operator, uint3, int1, float3);      \
    VECTOR1_VECTOR_ADD(Operator, uint3, uint1, float3);     \
                                                            \
    VECTOR1_VECTOR_ADD(Operator, uint4, int1, int4);        \
    VECTOR1_VECTOR_ADD(Operator, uint4, uint1, uint4);      \
    VECTOR1_VECTOR_ADD(Operator, uint4, int1, uint4);       \
    VECTOR1_VECTOR_ADD(Operator, uint4, uint1, int4);       \
    VECTOR1_VECTOR_ADD(Operator, uint4, float1, int4);      \
    VECTOR1_VECTOR_ADD(Operator, uint4, float1, uint4);     \
    VECTOR1_VECTOR_ADD(Operator, uint4, float1, float4);    \
    VECTOR1_VECTOR_ADD(Operator, uint4, int1, float4);      \
    VECTOR1_VECTOR_ADD(Operator, uint4, uint1, float4);     \
                                                            \
    VECTOR_VECTOR1_ADD(Operator, uint2, int2, int1);        \
    VECTOR_VECTOR1_ADD(Operator, uint2, uint2, uint1);      \
    VECTOR_VECTOR1_ADD(Operator, uint2, int2, uint1);       \
    VECTOR_VECTOR1_ADD(Operator, uint2, uint2, int1);       \
    VECTOR_VECTOR1_ADD(Operator, uint2, float2, int1);      \
    VECTOR_VECTOR1_ADD(Operator, uint2, float2, uint1);     \
    VECTOR_VECTOR1_ADD(Operator, uint2, float2, float1);    \
    VECTOR_VECTOR1_ADD(Operator, uint2, int2, float1);      \
    VECTOR_VECTOR1_ADD(Operator, uint2, uint2, float1);     \
                                                            \
    VECTOR_VECTOR1_ADD(Operator, uint3, int3, int1);        \
    VECTOR_VECTOR1_ADD(Operator, uint3, uint3, uint1);      \
    VECTOR_VECTOR1_ADD(Operator, uint3, int3, uint1);       \
    VECTOR_VECTOR1_ADD(Operator, uint3, uint3, int1);       \
    VECTOR_VECTOR1_ADD(Operator, uint3, float3, int1);      \
    VECTOR_VECTOR1_ADD(Operator, uint3, float3, uint1);     \
    VECTOR_VECTOR1_ADD(Operator, uint3, float3, float1);    \
    VECTOR_VECTOR1_ADD(Operator, uint3, int3, float1);      \
    VECTOR_VECTOR1_ADD(Operator, uint3, uint3, float1);     \
                                                            \
    VECTOR_VECTOR1_ADD(Operator, uint4, int4, int1);        \
    VECTOR_VECTOR1_ADD(Operator, uint4, uint4, uint1);      \
    VECTOR_VECTOR1_ADD(Operator, uint4, int4, uint1);       \
    VECTOR_VECTOR1_ADD(Operator, uint4, uint4, int1);       \
    VECTOR_VECTOR1_ADD(Operator, uint4, float4, int1);      \
    VECTOR_VECTOR1_ADD(Operator, uint4, float4, uint1);     \
    VECTOR_VECTOR1_ADD(Operator, uint4, float4, float1);    \
    VECTOR_VECTOR1_ADD(Operator, uint4, int4, float1);      \
    VECTOR_VECTOR1_ADD(Operator, uint4, uint4, float1);     \

#define GENERATE_OP2_PERMUTATION_NO_FLOATS(Operator)        \
    VECTOR_VECTOR_ADD(Operator, int1, int1, int1);          \
    VECTOR_VECTOR_ADD(Operator, uint1, uint1, uint1);       \
    VECTOR_VECTOR_ADD(Operator, int1, int1, uint1);         \
    VECTOR_VECTOR_ADD(Operator, int1, uint1, int1);         \
                                                            \
    VECTOR_VECTOR_ADD(Operator, int2, int2, int2);          \
    VECTOR_VECTOR_ADD(Operator, uint2, uint2, uint2);       \
    VECTOR_VECTOR_ADD(Operator, int2, int2, uint2);         \
    VECTOR_VECTOR_ADD(Operator, int2, uint2, int2);         \
                                                            \
    VECTOR_VECTOR_ADD(Operator, int3, int3, int3);          \
    VECTOR_VECTOR_ADD(Operator, uint3, uint3, uint3);       \
    VECTOR_VECTOR_ADD(Operator, int3, int3, uint3);         \
    VECTOR_VECTOR_ADD(Operator, int3, uint3, int3);         \
                                                            \
    VECTOR_VECTOR_ADD(Operator, int4, int4, int4);          \
    VECTOR_VECTOR_ADD(Operator, uint4, uint4, uint4);       \
    VECTOR_VECTOR_ADD(Operator, int4, int4, uint4);         \
    VECTOR_VECTOR_ADD(Operator, int4, uint4, int4);         \
                                                            \
    VECTOR_SCALAR_ADD(Operator, int1, int1, int);           \
    VECTOR_SCALAR_ADD(Operator, uint1, uint1, uint);        \
    VECTOR_SCALAR_ADD(Operator, int1, int1, uint);          \
    VECTOR_SCALAR_ADD(Operator, int1, uint1, int);          \
                                                            \
    VECTOR_SCALAR_ADD(Operator, int2, int2, int);           \
    VECTOR_SCALAR_ADD(Operator, uint2, uint2, uint);        \
    VECTOR_SCALAR_ADD(Operator, int2, int2, uint);          \
    VECTOR_SCALAR_ADD(Operator, int2, uint2, int);          \
                                                            \
    VECTOR_SCALAR_ADD(Operator, int3, int3, int);           \
    VECTOR_SCALAR_ADD(Operator, uint3, uint3, uint);        \
    VECTOR_SCALAR_ADD(Operator, int3, int3, uint);          \
    VECTOR_SCALAR_ADD(Operator, int3, uint3, int);          \
                                                            \
    VECTOR_SCALAR_ADD(Operator, int4, int4, int);           \
    VECTOR_SCALAR_ADD(Operator, uint4, uint4, uint);        \
    VECTOR_SCALAR_ADD(Operator, int4, int4, uint);          \
    VECTOR_SCALAR_ADD(Operator, int4, uint4, int);          \
                                                            \
    SCALAR_VECTOR_ADD(Operator, int1, int, int1);           \
    SCALAR_VECTOR_ADD(Operator, uint1, uint, uint1);        \
    SCALAR_VECTOR_ADD(Operator, int1, int, uint1);          \
    SCALAR_VECTOR_ADD(Operator, int1, uint, int1);          \
                                                            \
    SCALAR_VECTOR_ADD(Operator, int2, int, int2);           \
    SCALAR_VECTOR_ADD(Operator, uint2, uint, uint2);        \
    SCALAR_VECTOR_ADD(Operator, int2, int, uint2);          \
    SCALAR_VECTOR_ADD(Operator, int2, uint, int2);          \
                                                            \
    SCALAR_VECTOR_ADD(Operator, int3, int, int3);           \
    SCALAR_VECTOR_ADD(Operator, uint3, uint, uint3);        \
    SCALAR_VECTOR_ADD(Operator, int3, int, uint3);          \
    SCALAR_VECTOR_ADD(Operator, int3, uint, int3);          \
                                                            \
    SCALAR_VECTOR_ADD(Operator, int4, int, int4);           \
    SCALAR_VECTOR_ADD(Operator, uint4, uint, uint4);        \
    SCALAR_VECTOR_ADD(Operator, int4, int, uint4);          \
    SCALAR_VECTOR_ADD(Operator, int4, uint, int4);          \
                                                            \
    VECTOR1_VECTOR_ADD(Operator, int2, int1, int2);         \
    VECTOR1_VECTOR_ADD(Operator, uint2, uint1, uint2);      \
    VECTOR1_VECTOR_ADD(Operator, int2, int1, uint2);        \
    VECTOR1_VECTOR_ADD(Operator, int2, uint1, int2);        \
                                                            \
    VECTOR1_VECTOR_ADD(Operator, int3, int1, int3);         \
    VECTOR1_VECTOR_ADD(Operator, uint3, uint1, uint3);      \
    VECTOR1_VECTOR_ADD(Operator, int3, int1, uint3);        \
    VECTOR1_VECTOR_ADD(Operator, int3, uint1, int3);        \
                                                            \
    VECTOR1_VECTOR_ADD(Operator, int4, int1, int4);         \
    VECTOR1_VECTOR_ADD(Operator, uint4, uint1, uint4);      \
    VECTOR1_VECTOR_ADD(Operator, int4, int1, uint4);        \
    VECTOR1_VECTOR_ADD(Operator, int4, uint1, int4);        \
                                                            \
    VECTOR_VECTOR1_ADD(Operator, int2, int2, int1);         \
    VECTOR_VECTOR1_ADD(Operator, uint2, uint2, uint1);      \
    VECTOR_VECTOR1_ADD(Operator, int2, int2, uint1);        \
    VECTOR_VECTOR1_ADD(Operator, int2, uint2, int1);        \
                                                            \
    VECTOR_VECTOR1_ADD(Operator, int3, int3, int1);         \
    VECTOR_VECTOR1_ADD(Operator, uint3, uint3, uint1);      \
    VECTOR_VECTOR1_ADD(Operator, int3, int3, uint1);        \
    VECTOR_VECTOR1_ADD(Operator, int3, uint3, int1);        \
                                                            \
    VECTOR_VECTOR1_ADD(Operator, int4, int4, int1);         \
    VECTOR_VECTOR1_ADD(Operator, uint4, uint4, uint1);      \
    VECTOR_VECTOR1_ADD(Operator, int4, int4, uint1);        \
    VECTOR_VECTOR1_ADD(Operator, int4, uint4, int1);        \

//=========================================================================================================================================
// NOTE: General Assignemnt Operator
//=========================================================================================================================================

#define MACRO_ASSIGNMENT(Operator1, Operator2, ArgType1, ArgType2)  \
    ArgType1& operator##Operator1(ArgType1& A, ArgType2 B)          \
    {                                                               \
        A = A Operator2 B;                                          \
        return A;                                                   \
    }

#define GENERATE_ASSIGNMENT_PERMUTATION(Operator1, Operator2)   \
    MACRO_ASSIGNMENT(Operator1, Operator2, int1, int1);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, int1, uint1);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint1, uint1);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint1, int1);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, float1, int1);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, float1, uint1);      \
    MACRO_ASSIGNMENT(Operator1, Operator2, float1, float1);     \
                                                                \
    MACRO_ASSIGNMENT(Operator1, Operator2, int2, int2);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, int2, uint2);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint2, uint2);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint2, int2);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, float2, int2);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, float2, uint2);      \
    MACRO_ASSIGNMENT(Operator1, Operator2, float2, float2);     \
                                                                \
    MACRO_ASSIGNMENT(Operator1, Operator2, int3, int3);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, int3, uint3);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint3, uint3);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint3, int3);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, float3, int3);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, float3, uint3);      \
    MACRO_ASSIGNMENT(Operator1, Operator2, float3, float3);     \
                                                                \
    MACRO_ASSIGNMENT(Operator1, Operator2, int4, int4);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, int4, uint4);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint4, uint4);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint4, int4);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, float4, int4);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, float4, uint4);      \
    MACRO_ASSIGNMENT(Operator1, Operator2, float4, float4);     \
                                                                \
    MACRO_ASSIGNMENT(Operator1, Operator2, int2, int1);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, int2, uint1);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint2, uint1);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint2, int1);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, float2, int1);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, float2, uint1);      \
    MACRO_ASSIGNMENT(Operator1, Operator2, float2, float1);     \
                                                                \
    MACRO_ASSIGNMENT(Operator1, Operator2, int3, int1);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, int3, uint1);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint3, uint1);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint3, int1);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, float3, int1);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, float3, uint1);      \
    MACRO_ASSIGNMENT(Operator1, Operator2, float3, float1);     \
                                                                \
    MACRO_ASSIGNMENT(Operator1, Operator2, int4, int1);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, int4, uint1);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint4, uint1);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint4, int1);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, float4, int1);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, float4, uint1);      \
    MACRO_ASSIGNMENT(Operator1, Operator2, float4, float1);     \
                                                                \
    MACRO_ASSIGNMENT(Operator1, Operator2, int1, int);          \
    MACRO_ASSIGNMENT(Operator1, Operator2, int1, uint);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint1, uint);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint1, int);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, float1, int);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, float1, uint);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, float1, float);      \
                                                                \
    MACRO_ASSIGNMENT(Operator1, Operator2, int2, int);          \
    MACRO_ASSIGNMENT(Operator1, Operator2, int2, uint);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint2, uint);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint2, int);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, float2, int);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, float2, uint);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, float2, float);      \
                                                                \
    MACRO_ASSIGNMENT(Operator1, Operator2, int3, int);          \
    MACRO_ASSIGNMENT(Operator1, Operator2, int3, uint);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint3, uint);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint3, int);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, float3, int);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, float3, uint);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, float3, float);      \
                                                                \
    MACRO_ASSIGNMENT(Operator1, Operator2, int4, int);          \
    MACRO_ASSIGNMENT(Operator1, Operator2, int4, uint);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint4, uint);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint4, int);         \
    MACRO_ASSIGNMENT(Operator1, Operator2, float4, int);        \
    MACRO_ASSIGNMENT(Operator1, Operator2, float4, uint);       \
    MACRO_ASSIGNMENT(Operator1, Operator2, float4, float);      \

#define GENERATE_ASSIGNMENT_PERMUTATION_NO_FLOATS(Operator1, Operator2) \
    MACRO_ASSIGNMENT(Operator1, Operator2, int1, int1);                 \
    MACRO_ASSIGNMENT(Operator1, Operator2, int1, uint1);                \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint1, uint1);               \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint1, int1);                \
                                                                        \
    MACRO_ASSIGNMENT(Operator1, Operator2, int2, int2);                 \
    MACRO_ASSIGNMENT(Operator1, Operator2, int2, uint2);                \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint2, uint2);               \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint2, int2);                \
                                                                        \
    MACRO_ASSIGNMENT(Operator1, Operator2, int3, int3);                 \
    MACRO_ASSIGNMENT(Operator1, Operator2, int3, uint3);                \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint3, uint3);               \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint3, int3);                \
                                                                        \
    MACRO_ASSIGNMENT(Operator1, Operator2, int4, int4);                 \
    MACRO_ASSIGNMENT(Operator1, Operator2, int4, uint4);                \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint4, uint4);               \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint4, int4);                \
                                                                        \
    MACRO_ASSIGNMENT(Operator1, Operator2, int2, int1);                 \
    MACRO_ASSIGNMENT(Operator1, Operator2, int2, uint1);                \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint2, uint1);               \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint2, int1);                \
                                                                        \
    MACRO_ASSIGNMENT(Operator1, Operator2, int3, int1);                 \
    MACRO_ASSIGNMENT(Operator1, Operator2, int3, uint1);                \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint3, uint1);               \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint3, int1);                \
                                                                        \
    MACRO_ASSIGNMENT(Operator1, Operator2, int4, int1);                 \
    MACRO_ASSIGNMENT(Operator1, Operator2, int4, uint1);                \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint4, uint1);               \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint4, int1);                \
                                                                        \
    MACRO_ASSIGNMENT(Operator1, Operator2, int1, int);                  \
    MACRO_ASSIGNMENT(Operator1, Operator2, int1, uint);                 \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint1, uint);                \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint1, int);                 \
                                                                        \
    MACRO_ASSIGNMENT(Operator1, Operator2, int2, int);                  \
    MACRO_ASSIGNMENT(Operator1, Operator2, int2, uint);                 \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint2, uint);                \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint2, int);                 \
                                                                        \
    MACRO_ASSIGNMENT(Operator1, Operator2, int3, int);                  \
    MACRO_ASSIGNMENT(Operator1, Operator2, int3, uint);                 \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint3, uint);                \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint3, int);                 \
                                                                        \
    MACRO_ASSIGNMENT(Operator1, Operator2, int4, int);                  \
    MACRO_ASSIGNMENT(Operator1, Operator2, int4, uint);                 \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint4, uint);                \
    MACRO_ASSIGNMENT(Operator1, Operator2, uint4, int);                 \

//=========================================================================================================================================
// NOTE: Create all operators
//=========================================================================================================================================

GENERATE_OP2_PERMUTATION(+)
GENERATE_ASSIGNMENT_PERMUTATION(+=, +)
GENERATE_OP2_PERMUTATION(-)
GENERATE_ASSIGNMENT_PERMUTATION(-=, -)
GENERATE_OP2_PERMUTATION(*)
GENERATE_ASSIGNMENT_PERMUTATION(*=, *)
GENERATE_OP2_PERMUTATION(/)
GENERATE_ASSIGNMENT_PERMUTATION(/=, /)
GENERATE_OP2_PERMUTATION_NO_FLOATS(%)
GENERATE_ASSIGNMENT_PERMUTATION_NO_FLOATS(%=, %)

GENERATE_OP2_PERMUTATION_NO_FLOAT_RETURN(==)
GENERATE_OP2_PERMUTATION_NO_FLOAT_RETURN(!=)
GENERATE_OP2_PERMUTATION_NO_FLOAT_RETURN(||)
GENERATE_OP2_PERMUTATION_NO_FLOAT_RETURN(&&)
GENERATE_OP2_PERMUTATION_NO_FLOAT_RETURN(<)
GENERATE_OP2_PERMUTATION_NO_FLOAT_RETURN(<=)
GENERATE_OP2_PERMUTATION_NO_FLOAT_RETURN(>)
GENERATE_OP2_PERMUTATION_NO_FLOAT_RETURN(>=)

GENERATE_OP2_PERMUTATION_NO_FLOATS(|)
GENERATE_ASSIGNMENT_PERMUTATION_NO_FLOATS(|=, |)
GENERATE_OP2_PERMUTATION_NO_FLOATS(&)
GENERATE_ASSIGNMENT_PERMUTATION_NO_FLOATS(&=, &)
GENERATE_OP2_PERMUTATION_NO_FLOATS(^)
GENERATE_ASSIGNMENT_PERMUTATION_NO_FLOATS(^=, ^)
GENERATE_OP2_PERMUTATION_NO_FLOATS(<<)
GENERATE_ASSIGNMENT_PERMUTATION_NO_FLOATS(<<=, <<)
GENERATE_OP2_PERMUTATION_NO_FLOATS(>>)
GENERATE_ASSIGNMENT_PERMUTATION_NO_FLOATS(>>=, >>)

GENERATE_INCREMENT_PERMUTATION(++, +)
GENERATE_INCREMENT_PERMUTATION(--, -)
GENERATE_UNARY_PERMUTATION(+)
GENERATE_UNARY_PERMUTATION(-)
GENERATE_UNARY_PERMUTATION(!)
GENERATE_UNARY_PERMUTATION(~)

//=========================================================================================================================================
// NOTE: Dot Product
//=========================================================================================================================================

#define Dot2(ReturnType, ArgType1, ArgType2)        \
    ReturnType dot(ArgType1 A, ArgType2 B)          \
    {                                               \
        ReturnType Result = A.x * B.x + A.y * B.y;  \
        return Result;                              \
    }                                               \

#define Dot3(ReturnType, ArgType1, ArgType2)                    \
    ReturnType dot(ArgType1 A, ArgType2 B)                      \
    {                                                           \
        ReturnType Result = A.x * B.x + A.y * B.y + A.z * B.z;  \
        return Result;                                          \
    }                                                           \

#define Dot4(ReturnType, ArgType1, ArgType2)                            \
    ReturnType dot(ArgType1 A, ArgType2 B)                              \
    {                                                                   \
        ReturnType Result = A.x * B.x + A.y * B.y + A.z * B.z + A.w * B.w; \
        return Result;                                                  \
    }                                                                   \

Dot2(int2, int2, int2);
Dot2(int2, int2, uint2);
Dot2(int2, uint2, int2);
Dot2(uint2, uint2, uint2);
Dot2(float2, float2, int2);
Dot2(float2, float2, uint2);
Dot2(float2, float2, float2);
Dot2(float2, int2, float2);
Dot2(float2, uint2, float2);

Dot3(int3, int3, int3);
Dot3(int3, int3, uint3);
Dot3(int3, uint3, int3);
Dot3(uint3, uint3, uint3);
Dot3(float3, float3, int3);
Dot3(float3, float3, uint3);
Dot3(float3, float3, float3);
Dot3(float3, int3, float3);
Dot3(float3, uint3, float3);

Dot4(int4, int4, int4);
Dot4(int4, int4, uint4);
Dot4(int4, uint4, int4);
Dot4(uint4, uint4, uint4);
Dot4(float4, float4, int4);
Dot4(float4, float4, uint4);
Dot4(float4, float4, float4);
Dot4(float4, int4, float4);
Dot4(float4, uint4, float4);

//=========================================================================================================================================
// NOTE: All function
//=========================================================================================================================================

#define All2(ArgType)                           \
    uint1 all(ArgType A)                        \
    {                                           \
        uint1 Result = A.x && A.y;              \
        return Result;                          \
    }                                           \

#define All3(ArgType)                           \
    uint1 all(ArgType A)                        \
    {                                           \
        uint1 Result = A.x && A.y && A.z;       \
        return Result;                          \
    }                                           \

#define All4(ArgType)                               \
    uint1 all(ArgType A)                            \
    {                                               \
        uint1 Result = A.x && A.y && A.z && A.w;    \
        return Result;                              \
    }                                               \

All2(int2)
All2(uint2)
All2(float2)

All3(int3)
All3(uint3)
All3(float3)

All4(int4)
All4(uint4)
All4(float4)

//=========================================================================================================================================
// NOTE: Condition Helpers
//=========================================================================================================================================

uint1 EvaluteConditionMask(uint1 A)
{
    uint1 Result = {};
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Result.Data[ThreadId] = A.Data[ThreadId] ? 0xFFFFFFFF : 0;
    }

    return Result;
}

bool EvaluteConditionScalar(uint1 A)
{
    bool Result = false;
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        Result = A.Data[ThreadId] || Result;
    }

    return Result;
}

void RestoreExecMask()
{
    // NOTE: We do this because every math op is overwritten to use the exec mask implicitly
    _NumSavedExecMasks -= 1;
    for (int ThreadId = 0; ThreadId < WAVE_SIZE; ++ThreadId)
    {
        _GlobalExecMask.Data[ThreadId] = _SavedExecMasks[_NumSavedExecMasks].Data[ThreadId];
    }
}

//=========================================================================================================================================
// NOTE: If Statement
//=========================================================================================================================================

#define IF(Condition)                                                   \
    _SavedExecMasks[_NumSavedExecMasks++] = _GlobalExecMask;            \
    _GlobalExecMask = _GlobalExecMask & EvaluteConditionMask(Condition); \
    if (EvaluteConditionScalar(Condition))                              \

#define END_IF                                  \
    RestoreExecMask();                          \

// TODO: Add RETURN STATEMENT

//=========================================================================================================================================
// NOTE: For Statement
//=========================================================================================================================================

#define FOR(VarDefinition, Condition, Increment)                        \
    _SavedExecMasks[_NumSavedExecMasks++] = _GlobalExecMask;            \
    for (VarDefinition; EvaluteConditionScalar(Condition); Increment)   \
    {                                                                   \
    _GlobalExecMask = _GlobalExecMask & EvaluteConditionMask(Condition); \

#define END_FOR                                 \
    }                                           \
    RestoreExecMask();                          \
