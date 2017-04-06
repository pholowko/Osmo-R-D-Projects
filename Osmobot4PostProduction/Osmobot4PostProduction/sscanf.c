/* ************************************************************************* 
  DESCRIPTION:  Implementation of scanf() using CCS C compiler 
  RETURN: total number of arguments read 
  ALGORITHM:  none 
  NOTES:  none 
 *************************************************************************** */ 
int8 sscanf( 
  char  *buf,    /* pointer to the buffer that we are scanning */ 
  char  *fmt,    /* pointer to the format string */ 
         ...)      /* variable arguments */ 
{ 

  va_list      pArgs; 
  int8        count = 0; 
  char        *p; 
  int1        size_long; 
  int1        sign; 
  char        *endptr; 

  va_start (pArgs,0); 

  while (TRUE) 
  { 


   /* Gobble up the fmt string */ 
    while (*buf == *fmt) 
    { 
      if ((*buf == 0) || (*fmt == 0)) 
        return (count); 
     
      buf++; 
      fmt++; 
    } 

    /* Check for the % */ 
    if (*fmt != '%') 
      break; 

    /* fmt should be '%' go to the next character */ 
    fmt++; 

    /* get the size modifier */ 
    switch (*fmt) 
    { 
      case 'l': 
      case 'L': 
        fmt++; 
        size_long = TRUE; 
        break; 
      default: 
        size_long = FALSE; 
        break; 
    } 

    /* fmt should point to our first conversion letter at this point */ 
    switch (*fmt) 
    { 
#ifndef NO_FLOAT 
      case 'f': 
      case 'F': 

        /* convert to a number */ 
        *((float *)va_arg(pArgs,float*)) = my_atof(buf, &endptr); 

        /* Make sure that we succeeded */ 
        if ( buf == endptr ) 
          return ( count );        
    
        buf = endptr; 

        /* count this one */ 
        count++; 
        break; 
#endif 
#ifndef NO_SIGNED_INT 
      case 'd': 
      case 'D': 
        /* Get a pointer to this argument */ 
        p = va_arg(pArgs,signed int16*); 

        if (*buf == '-') 
        { 
          buf++; 
          sign = TRUE; 
        } 
        else 
          sign = FALSE; 

        /* convert to a number */ 
        if ( size_long ) 
        { 
          *(signed int16 *)p = (signed int16)my_atoul(buf, &endptr, 10); 
          if (sign) 
            *(signed int16 *)p = -(*(signed int16 *)p); 
        } 
        else 
        { 
          *(signed int8 *)p = (signed int8)my_atoul(buf, &endptr, 10); 
          if (sign) 
            *(signed int8 *)p = -(*(signed int8 *)p); 
        } 
        /* Make sure that we succeeded */ 
        if ( buf == endptr ) 
          return ( count ); 
       
        buf = endptr; 

        /* count this one */ 
        count++; 
        break; 
#endif 
#ifndef NO_INT 
      case 'u': 
      case 'U': 

        /* convert to a number */ 
        if ( size_long ) 
          *((int16*)va_arg(pArgs,int16*)) = (int16) my_atoul(buf, &endptr, 10); 
        else 
          *((int8 *)va_arg(pArgs,int8*))  = (int8) my_atoul(buf, &endptr, 10); 

        /* Make sure that we succeeded */ 
        if ( buf == endptr ) 
          return ( count ); 
       
        buf = endptr; 

        /* count this one */ 
        count++; 
        break; 
#endif 
#ifndef NO_STRING 
      case 's': 
        /* Get a pointer to this argument */ 
        p = (char *) va_arg(pArgs,char *); 

        /* copy the chars */ 
        while (TRUE) 
        { 
          if ((isspace(*buf)) || (!*buf)) 
          { 
            *p = 0; 
            break; 
          } 
          else 
          { 
            *p = *buf; 
            p++; 
            buf++; 
          } 
        } 

        /* count this one */ 
        count++; 
        break; 
#endif 
#ifndef NO_HEX 
      case 'x': 
      case 'X': 
        

        /* convert to a number */ 
        if ( size_long ) 
          *((int16*)va_arg(pArgs,int16*)) = (int16) my_atoul(buf, &endptr, 16); 
        else 
          *((int8 *)va_arg(pArgs,int8*))  = (int8) my_atoul(buf, &endptr, 16); 

        /* Make sure that we succeeded */ 
        if ( buf == endptr ) 
          return ( count ); 
       
        buf = endptr; 

        /* count this one */ 
        count++; 
        break; 
#endif 
      /* unhandled format specifier */ 
      default: 
        return (count); 
    } 

    
    /* Move to the next format char */ 
    fmt++; 
  } 
    
  return (count); 
}