#if !defined(REGISTERS_H)

/*
    NOTE: Things to think about for each op

     - Vector Vector operators
     - Vector Scalar operators
     - Scalar Vector operators
     - Vector Vector1 operators
     - Vector1 Vector operators

 */

#define WAVE_SIZE 64

typedef unsigned int uint;

struct int1;
struct int2;
struct int3;
struct int4;
struct uint1;
struct uint2;
struct uint3;
struct uint4;
struct float1;
struct float2;
struct float3;
struct float4;

//=========================================================================================================================================
// NOTE: Integer types
//=========================================================================================================================================

struct int1
{
    int Data[WAVE_SIZE];

    int1();
    int1(const int& A);
    int1(const uint& A);
    int1(const uint1& A);

    static int Size() { return 1; }

    int1& operator[](int Index)
    {
        return *this;
    }

    int1& operator=(const int1& A);

    int1 operator+() const;
    int1 operator-() const;
    int1 operator!() const;
    int1 operator~() const;
    int1& operator++();
    int1 operator++(int);
    int1& operator--();
    int1 operator--(int);
};

struct int2
{
    union
    {
        struct
        {
            int1 x;
            int1 y;
        };

        int1 Elements[2];
    };
    
    int2();
    int2(const int& A);
    int2(const uint& A);
                                
    int2(const int1& A);
    int2(const uint1& A);

    int2(const uint2& A);

    int2(int X, int Y);
    
    static int Size() { return 2; }

    int1& operator[](int Index)
    {
        return Elements[Index];
    }

    int2& operator=(const int2& A);

    int2 operator+() const;
    int2 operator-() const;
    int2 operator!() const;
    int2 operator~() const;
    int2& operator++();
    int2 operator++(int);
    int2& operator--();
    int2 operator--(int);
};

struct int3
{
    union
    {
        struct
        {
            int1 x;
            int1 y;
            int1 z;
        };

        struct
        {
            int2 xy;
            int1 UnUsed0;
        };

        struct
        {
            int1 UnUsed1;
            int2 yz;
        };

        int1 Elements[3];
    };
    
    int3();
    int3(const int& A);
    int3(const uint& A);
                        
    int3(const int1& A);
    int3(const uint1& A);

    int3(const uint3& A);

    int3(int X, int Y, int Z);
    int3(int2 XY, int Z);
    int3(int1 X, int2 YZ);
    
    static int Size() { return 3; }

    int1& operator[](int Index)
    {
        return Elements[Index];
    }
    
    int3& operator=(const int3& A);

    int3 operator+() const;
    int3 operator-() const;
    int3 operator!() const;
    int3 operator~() const;
    int3& operator++();
    int3 operator++(int);
    int3& operator--();
    int3 operator--(int);
};

struct int4
{
    union
    {
        struct
        {
            int1 x;
            int1 y;
            int1 z;
            int1 w;
        };

        struct
        {
            int3 xyz;
            int1 UnUsed0;
        };

        struct
        {
            int1 UnUsed1;
            int3 yzw;
        };

        struct
        {
            int2 xy;
            int2 zw;
        };

        struct
        {
            int1 UnUsed2;
            int2 yz;
            int1 UnUsed4;
        };

        int1 Elements[4];
    };
    
    int4();
    int4(const int& A);
    int4(const uint& A);
                            
    int4(const int1& A);
    int4(const uint1& A);

    int4(const uint4& A);

    int4(int X, int Y, int Z, int W);
    int4(int2 XY, int2 ZW);
    int4(int3 XYZ, int1 W);
    int4(int1 X, int3 YZW);

    static int Size() { return 4; }

    int1& operator[](int Index)
    {
        return Elements[Index];
    }

    int4& operator=(const int4& A);

    int4 operator+() const;
    int4 operator-() const;
    int4 operator!() const;
    int4 operator~() const;
    int4& operator++();
    int4 operator++(int);
    int4& operator--();
    int4 operator--(int);
};

//=========================================================================================================================================
// NOTE: Unsigned Integer Types
//=========================================================================================================================================

struct uint1
{
    uint Data[WAVE_SIZE];

    uint1();
    uint1(const int& A);
    uint1(const uint& A);
    uint1(const int1& A);

    static int Size() { return 1; }

    uint1& operator[](int Index)
    {
        return *this;
    }

    uint1& operator=(const uint1& A);

    uint1 operator+() const;
    uint1 operator-() const;
    uint1 operator!() const;
    uint1 operator~() const;
    uint1& operator++();
    uint1 operator++(int);
    uint1& operator--();
    uint1 operator--(int);
};

struct uint2
{
    union
    {
        struct
        {
            uint1 x;
            uint1 y;
        };

        uint1 Elements[2];
    };

    uint2();
    uint2(const int& A);
    uint2(const uint& A);
                    
    uint2(const int1& A);
    uint2(const uint1& A);

    uint2(const int2& A);

    uint2(uint X, uint Y);

    static int Size() { return 2; }

    uint1& operator[](int Index)
    {
        return Elements[Index];
    }

    uint2& operator=(const uint2& A);

    uint2 operator+() const;
    uint2 operator-() const;
    uint2 operator!() const;
    uint2 operator~() const;
    uint2& operator++();
    uint2 operator++(int);
    uint2& operator--();
    uint2 operator--(int);
};

struct uint3
{
    union
    {
        struct
        {
            uint1 x;
            uint1 y;
            uint1 z;
        };

        struct
        {
            uint2 xy;
            uint1 UnUsed0;
        };

        struct
        {
            uint1 UnUsed1;
            uint2 yz;
        };

        uint1 Elements[3];
    };
    
    uint3();
    uint3(const int& A);
    uint3(const uint& A);
                
    uint3(const int1& A);
    uint3(const uint1& A);

    uint3(const int3& A);

    uint3(uint X, uint Y, uint Z);
    uint3(uint2 XY, uint Z);
    uint3(uint1 X, uint2 YZ);

    static int Size() { return 3; }

    uint1& operator[](int Index)
    {
        return Elements[Index];
    }

    uint3& operator=(const uint3& A);

    uint3 operator+() const;
    uint3 operator-() const;
    uint3 operator!() const;
    uint3 operator~() const;
    uint3& operator++();
    uint3 operator++(int);
    uint3& operator--();
    uint3 operator--(int);
};

struct uint4
{
    union
    {
        struct
        {
            uint1 x;
            uint1 y;
            uint1 z;
            uint1 w;
        };

        struct
        {
            uint3 xyz;
            uint1 UnUsed0;
        };

        struct
        {
            uint1 UnUsed1;
            uint3 yzw;
        };

        struct
        {
            uint2 xy;
            uint2 zw;
        };

        struct
        {
            uint1 UnUsed2;
            uint2 yz;
            uint1 UnUsed4;
        };

        uint1 Elements[4];
    };
    
    uint4();
    uint4(const int& A);
    uint4(const uint& A);
            
    uint4(const int1& A);
    uint4(const uint1& A);

    uint4(const int4& A);

    uint4(uint X, uint Y, uint Z, uint W);
    uint4(uint2 XY, uint2 ZW);
    uint4(uint3 XYZ, uint1 W);
    uint4(uint1 X, uint3 YZW);

    static int Size() { return 4; }

    uint1& operator[](int Index)
    {
        return Elements[Index];
    }

    uint4& operator=(const uint4& A);

    uint4 operator+() const;
    uint4 operator-() const;
    uint4 operator!() const;
    uint4 operator~() const;
    uint4& operator++();
    uint4 operator++(int);
    uint4& operator--();
    uint4 operator--(int);
};

//=========================================================================================================================================
// NOTE: Float Types
//=========================================================================================================================================

struct float1
{
    float Data[WAVE_SIZE];

    float1();
    float1(const int& A);
    float1(const uint& A);
    float1(const float& A);
    float1(const int1& A);
    float1(const uint1& A);

    static int Size() { return 1; }

    float1& operator[](int Index)
    {
        return *this;
    }

    float1& operator=(const float1& A);

    float1 operator+() const;
    float1 operator-() const;
    float1 operator!() const;
    float1 operator~() const;
    float1& operator++();
    float1 operator++(int);
    float1& operator--();
    float1 operator--(int);
};

struct float2
{
    union
    {
        struct
        {
            float1 x;
            float1 y;
        };

        float1 Elements[2];
    };

    float2();
    float2(const int& A);
    float2(const uint& A);
    float2(const float& A);
        
    float2(const int1& A);
    float2(const uint1& A);
    float2(const float1& A);

    float2(const int2& A);
    float2(const uint2& A);

    float2(float X, float Y);

    static int Size() { return 2; }

    float1& operator[](int Index)
    {
        return Elements[Index];
    }

    float2& operator=(const float2& A);

    float2 operator+() const;
    float2 operator-() const;
    float2 operator!() const;
    float2 operator~() const;
    float2& operator++();
    float2 operator++(int);
    float2& operator--();
    float2 operator--(int);
};

struct float3
{
    union
    {
        struct
        {
            float1 x;
            float1 y;
            float1 z;
        };

        struct
        {
            float2 xy;
            float1 UnUsed0;
        };

        struct
        {
            float1 UnUsed1;
            float2 yz;
        };

        float1 Elements[3];
    };
    
    float3();
    float3(const int& A);
    float3(const uint& A);
    float3(const float& A);
    
    float3(const int1& A);
    float3(const uint1& A);
    float3(const float1& A);

    float3(const int3& A);
    float3(const uint3& A);

    float3(float X, float Y, float Z);
    float3(float2 XY, float Z);
    float3(float1 X, float2 YZ);

    static int Size() { return 3; }

    float1& operator[](int Index)
    {
        return Elements[Index];
    }

    float3& operator=(const float3& A);

    float3 operator+() const;
    float3 operator-() const;
    float3 operator!() const;
    float3 operator~() const;
    float3& operator++();
    float3 operator++(int);
    float3& operator--();
    float3 operator--(int);
};

struct float4
{
    union
    {
        struct
        {
            float1 x;
            float1 y;
            float1 z;
            float1 w;
        };

        struct
        {
            float3 xyz;
            float1 UnUsed0;
        };

        struct
        {
            float1 UnUsed1;
            float3 yzw;
        };

        struct
        {
            float2 xy;
            float2 zw;
        };

        struct
        {
            float1 UnUsed2;
            float2 yz;
            float1 UnUsed4;
        };

        float1 Elements[4];
    };
    
    float4();
    float4(const int& A);
    float4(const uint& A);
    float4(const float& A);

    float4(const int1& A);
    float4(const uint1& A);
    float4(const float1& A);
    
    float4(const int4& A);
    float4(const uint4& A);

    float4(float X, float Y, float Z, float W);
    float4(float2 XY, float2 ZW);
    float4(float3 XYZ, float1 W);
    float4(float1 X, float3 YZW);
    
    static int Size() { return 4; }

    float1& operator[](int Index)
    {
        return Elements[Index];
    }

    float4& operator=(const float4& A);

    float4 operator+() const;
    float4 operator-() const;
    float4 operator!() const;
    float4 operator~() const;
    float4& operator++();
    float4 operator++(int);
    float4& operator--();
    float4 operator--(int);
};

static uint1 _GlobalExecMask;
static uint1 _GlobalReturnMask;

static uint _NumSavedExecMasks;
static uint1 _SavedExecMasks[1000];

#define REGISTERS_H
#endif
