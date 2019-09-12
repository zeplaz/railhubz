
#include "rail_trainz.hpp"
#include <cstring>

#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>


  #include <SFML/OpenGL.hpp>



  size_t strlcpy(char *, const char *, size_t);

  /*
   * Copy src to string dst of size siz.  At most siz-1 characters
   * will be copied.  Always NUL terminates (unless siz == 0).
   * Returns strlen(src); if retval >= siz, truncation occurred.
   */
  size_t
  strlcpy(char *dst, const char *src, size_t siz)
  {
          char *d = dst;
          const char *s = src;
          size_t n = siz;

          /* Copy as many bytes as will fit */
          if (n != 0 && --n != 0) {
                  do {
                          if ((*d++ = *s++) == 0)
                                  break;
                  } while (--n != 0);
          }

          /* Not enough room in dst, add NUL and traverse rest of src */
          if (n == 0) {
                  if (siz != 0)
                          *d = '\0';                /* NUL-terminate dst */
                  while (*s++)
                          ;
          }

          return(s - src - 1);        /* count does not include NUL */
  }

int main(int argc, char** argv)
  {
    int total_entiez;

    char src[] = "It's Monday and it's raining";
    char dest[20];
    //strcpy_s(src,dest,sizeof(dest));
    //strlcpy(src,dest,sizeof(dest));
    printf("%s \n",dest);

#ifdef __STDC_LIB_EXT1__
    set_constraint_handler_s(ignore_handler_s);
    int r = strcpy_s(dst, sizeof dst, src);
    printf("dst = \"%s\", r = %d\n", dst, r);
    r = strcpy_s(dst, sizeof dst, "Take even more tests.");
    printf("dst = \"%s\", r = %d\n", dst, r);
#endif

    R_linez line1(total_entiez);
    R_linez line2(total_entiez);

    line1.initialize(12.f, 100.f, 30.f,50.f);
    line2.initialize(120.f, 10.f, 20.f,100.f);
    trainz train_1(total_entiez);
    trainz train_2(total_entiez);
    //create window and framez

    sf::RenderWindow p_window (sf::VideoMode(700,800), "Test_hub1");
    p_window.setFramerateLimit(60);

    while (p_window.isOpen())
    {
      sf::Event prim_evt;

      while (p_window.pollEvent(prim_evt))
      {
        if (prim_evt.type ==sf::Event::Closed)
                    p_window.close();

        if (prim_evt.type == sf::Event::Resized)
        glViewport(0, 0, prim_evt.size.width, prim_evt.size.height);
      }//endpolling

      p_window.clear();

      line1.draw(p_window);
      line2.draw(p_window);

      p_window.display();

    }//end mainwindowloop

   return 0;
  }
