ptr[30000];
i 0;
main ()
{
  extrn putchar, getchar, ptr, i;

  while (i < 30000)
    {
      ptr[i] = 0;
      i++;
    }
  i = 0;
  i++;
  ptr[i] =- 10;
  i =+ 3;
  ptr[i]++;
  i++;
  ptr[i]++;
  while (ptr[i])
    {
      i =+ 3;
      ptr[i]++;
      while (ptr[i])
    {
      ptr[i]--;
      while (ptr[i])
        {
          i =- 5;
          while (ptr[i])
        {
          ptr[i]++;
          i =- 5;
        }
          i =+ 2;
          while (ptr[i])
        {
          while (ptr[i])
            {
              ptr[i]--;
            }
          i++;
          while (ptr[i])
            {
              i =- 2;
              ptr[i]++;
              i++;
              ptr[i]++;
              i++;
              ptr[i]--;
            }
          i--;
          while (ptr[i])
            {
              i++;
              ptr[i]++;
              i--;
              ptr[i]--;
            }
          i--;
          while (ptr[i])
            {
              i++;
              ptr[i]++;
              i--;
              ptr[i]--;
              while (ptr[i])
            {
              i++;
              ptr[i]++;
              i--;
              ptr[i]--;
              while (ptr[i])
                {
                  i++;
                  ptr[i]++;
                  i--;
                  ptr[i]--;
                  while (ptr[i])
                {
                  i++;
                  ptr[i]++;
                  i--;
                  ptr[i]--;
                  while (ptr[i])
                    {
                      i++;
                      ptr[i]++;
                      i--;
                      ptr[i]--;
                      while (ptr[i])
                    {
                      i++;
                      ptr[i]++;
                      i--;
                      ptr[i]--;
                      while (ptr[i])
                        {
                          i++;
                          ptr[i]++;
                          i--;
                          ptr[i]--;
                          while (ptr[i])
                        {
                          i++;
                          ptr[i]++;
                          i--;
                          ptr[i]--;
                          while (ptr[i])
                            {
                              i++;
                              ptr[i]++;
                              i--;
                              ptr[i]--;
                              while (ptr[i])
                            {
                              i++;
                              while (ptr[i])
                                {
                                  ptr[i]--;
                                }
                              i =+ 4;
                              ptr[i]++;
                              i++;
                              ptr[i]++;
                              i =- 6;
                              ptr[i]--;
                              while (ptr[i])
                                {
                                  i++;
                                  ptr[i]++;
                                  i--;
                                  ptr[i]--;
                                }
                            }
                            }
                        }
                        }
                    }
                    }
                }
                }
            }
            }
          i++;
          while (ptr[i])
            {
              i--;
              ptr[i]++;
              i++;
              ptr[i]--;
            }
          ptr[i]++;
          i =+ 5;
        }
          i =- 5;
          while (ptr[i])
        {
          i =- 5;
        }
          i =+ 7;
          while (ptr[i])
        {
          i =+ 5;
        }
          ptr[i] =- 2;
          while (ptr[i])
        {
          ptr[i]--;
          i =- 5;
        }
          i =+ 6;
          ptr[i]--;
        }
      ptr[i]++;
      i =+ 5;
    }
      i--;
      while (ptr[i])
    {
      i++;
      ptr[i] =- 2;
      i--;
      ptr[i]--;
    }
      i =- 4;
      while (ptr[i])
    {
      i--;
      while (ptr[i])
        {
          i++;
          ptr[i]++;
          i--;
          ptr[i]--;
        }
      i =- 4;
    }
      i =+ 2;
      while (ptr[i])
    {
      ptr[i]--;
      i++;
      while (ptr[i])
        {
          ptr[i]--;
        }
      ptr[i] =- 6;
      while (ptr[i])
        {
          i--;
          ptr[i] =- 8;
          i++;
          ptr[i]--;
        }
      i =+ 4;
    }
      i =- 5;
      while (ptr[i])
    {
      i--;
      while (ptr[i])
        {
          i++;
          ptr[i]++;
          i++;
          ptr[i]++;
          i =- 2;
          ptr[i]--;
        }
      i++;
      putchar (ptr[i]);
      i =- 5;
    }
      i++;
      putchar (ptr[i]);
      i =+ 4;
    }
  return 0;
}