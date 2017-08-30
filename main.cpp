#include "router.h"
#include "netlist_helper.h"
#include "interlayer.h"

#include "connectivity.h"

void manual_way(ZChannelRouter& router) {
  
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

}


void automated_way(ZChannelRouter& router) {
    
    ZNetlisterHelper nh(&router);  
            nh.top_row()    << "N0" << "N1" << "N4" << "N5" << "N1" << "N6" << "N7" << "N0" << "N4" << "N9" << "N10" << "N10";
            nh.buttom_row() << "N2" << "N3" << "N5" << "N3" << "N5" << "N2" << "N6" << "N8" << "N9" << "N8" <<  "N7" << "N9";
      
    //router.load(nh.get());	      
    router.route();	    
}

int main( int argc, char* args[] )
{
	
        ZChannelRouter router;
        ZInterLayer il(&router);
        
      
        manual_way(router);
        //automated_way(router);
        
        il.start();    
        il.end();
        
        return 0;
}