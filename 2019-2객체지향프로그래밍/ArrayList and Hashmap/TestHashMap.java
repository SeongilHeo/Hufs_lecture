/* HashMap is used to store Student objects as value and 
   rollnos as keys.
   We are using the same Student class which we build in our
    previous lectures */

import java.util.*;

public class TestHashMap {
  public static void main (String args[]){

	  HashMap <String, Student> h;
	  h=new	 HashMap<String, Student>(); 

     Student s1 = new Student("ali", 1);
     Student s2 = new Student("saad", 2);
     Student s3 = new Student("raza", 6);

     h.put("one", s1 ); //(key, data)
     h.put("two", s2 );
     h.put("six", s3 );     

     boolean b = h.isEmpty();
     
     if (b == true){

        System.out.println("hashmap is empty");
     }  
     else {

         int size = h.size();  

         System.out.println("hashmap size:"+ size);     
     }

     Student s = (Student) h.get("two");
     s.print();    
          
  } //end of main
}

