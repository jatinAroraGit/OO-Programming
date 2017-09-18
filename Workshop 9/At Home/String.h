//guards
#ifndef SICT_STRING_H_
#define SICT_STRING_H_

#include <iostream>

//namespace block
namespace sict
{
//class declaration
    class String
    {
        //c-style string pointer
        char *m_pString;
        
       //length of string
        int m_capacity;     
    public:
        //constructors
        String(int size=1);
      
        String(const char* src, int size=1);
        // a copy constructor
        String(const String& src, int size=1);
       //operator 
        String& operator=(const String& src);
        // the destructor
        ~String();


        //member functions
        virtual void resize (int newsize);
        
        int capacity    ()              { return m_capacity; }
       
        int         length()                    const;
      
        bool        empty   ()                  const;
       
        String      substr  (int index, int len)const;

      
   
        String&     operator+=  (char c);
       
        String&     operator+=  (const String& s2);
   
        String      operator+   (const String& s2) const;
  
        operator    const char* ()                  const;
     
        operator    bool        ()                  const;
     
        bool        operator==(const String& s2)const;
        
        
        
   };

    // global helper functions
    std::ostream&    operator<<  (std::ostream&, const String&);
    std::istream&    operator>>  (std::istream&, String&);



   

};

#endif
