
main()
{
    auto a, b[], c[10];
    extrn x, y, z, foo;

    a = 3;
    b = &x;
    z[a] = ++*b++;
    while(z)
    {
        if(z[b?a++-c[a=^*b]:4&b])
        {
            switch (z[++*a%x[c[&b]?(a===b):y&b]])()
            {
                case 1:
                foo(x, y, z);
                break;
                default: {}
                break;
            }
        }
    }
}

foo(a, b, c)
switch a
{
    default:
    break;    
}

x[4] 1, 2, 3, 4;
y;
z[5] 1, x, y;