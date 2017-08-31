Channel Router (VLSI)
===
This is just-for-fun educational project to design implement and render 
channel routing algorithm,the most commonly used routing strategy for VLSI routing.

There is several algorihtms used in channel routing, Implementing leftEdge and greedy

Acutal drawing ( interlayer.h ) is library independed, but current implementation is
using SDL as base renderer. Dependcy kept minimal , so should be very easy to port to Qt or other library.

Example.
---
Input:
Upper Row: N0 N1 N4 N5 N1 N6 N7 N0 N4 N9 N10 N10

Lower Row: N2 N3 N5 N3 N5 N2 N6 N8 N9 N8 N7 N9

Ouput:

<img src="https://image.ibb.co/cudUj5/13.png">

Also it is possible to have metal view rendering ( leftclick ). 
Assuming tracks are on metal1 , segments are on metal2.

<img src="https://image.ibb.co/dDqs45/2222.png">


Code interfaces.
---

Input to the router should be nets, and where every net could have terminal assigned to ....

```
     ZChannelRouter router;
     ZNetlisterHelper nh(&router);  
            nh.top_row()    << "N0" << "N1" << "N4" << "N5" << "N1" << "N6" << "N7" << "N0" << "N4" << "N9" << "N10" << "N10";
            nh.buttom_row() << "N2" << "N3" << "N5" << "N3" << "N5" << "N2" << "N6" << "N8" << "N9" << "N8" <<  "N7" << "N9";
      
    //router.load(nh.get());	      
    router.route();	    
```

or more "manual" way, adding each invidual net and it's corresponding terminal one by one

```
     ZChannelRouter router;
     ZNet* a = new ZNet("A");
        a->add_term(0,ZUpperTerm);
        a->add_term(2,ZUpperTerm);
            
    ZNet* b = new ZNet("B");
        b->add_term(1,ZUpperTerm);
        b->add_term(0,ZLowerTerm);
        
    ZNet* c = new ZNet("C");
        c->add_term(3,ZUpperTerm);
        c->add_term(1,ZLowerTerm);
        c->add_term(2,ZLowerTerm);

    router.add_net_to_route(a);
    router.add_net_to_route(b);
    router.add_net_to_route(c);
  
    router.route();
```


Limitations.
---
TODO

Dependencies.
---
TODO



