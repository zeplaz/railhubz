
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
