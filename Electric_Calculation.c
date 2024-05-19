#include<stdio.h>
float ft ;
struct result{
	float energy;
	float service;
	float reactive;
	float total_ele;
	float use_energy;
	float vat;
	float total;
}ans;
display(struct result ans){
    printf("Energy Charge : %.2f bath", ans.energy);
    printf("\nService Charge : %.2f bath", ans.service);
    printf("\nTotal Base Tariff : %.2f bath", ans.total_ele);
    printf("\nUsed Energy x Ft Rate : %.2f bath", ans.use_energy);
    printf("\nVAT : %.2f bath", ans.vat);
    printf("\nTotal Electricity Charge : %.2f bath", ans.total);
}
MonandYear(){
	int month,year;
	printf("\t---YEAR---\n  1.2565  2.2566\n");
	printf("\t---MONTH---\n  1.January\t2.February\n  3.March\t4.April\n  5.May   \t6.June\n  7.July\t8.August\n  9.September\t10.October\n  11.November\t12.December\n");
	printf("Enter number year :");
	scanf("%d",&year);	
	if(year == 2){		
		printf("Enter number month :");
		scanf("%d",&month);
		if(month <= 4){
			ft = 0.9343;
		}
		else{
			printf(" ERROR ");
		}
	}
	else if(year == 1){
		printf("\nEnter number month :");
		scanf("%d",&month);	
		if(month <= 4){
			ft = 0.0139;
		}
		else if(month > 4 && month <= 8){
			ft = 0.2477;
		}
		else if(month > 8 && month <= 12){
			ft = 0.9343;
		}
		else{
			printf(" ERROR ");
		}
	}
	else{
		printf(" ERROR ");
	}
}
cal_1(int x,int unit,float service){
	int use = unit;
    float energy; 
    if(x==1){
	    if (unit > 0 && unit <= 15){
	        energy += unit * 2.3488;
	    }
	    else if (unit > 15 && unit <= 25){
	        energy = 15 * 2.3488;
			use = use - 15;
            energy += use * 2.9882;       
       	}           	    
		else if (unit > 25 && unit <= 35){
			energy = 15 * 2.3488; 
			use = use - 15;
	        energy += 10 * 2.9882;
	        use = use - 10;
	        energy += use * 3.2405;
	    }	    
		else if (unit > 35 && unit <= 100){
			energy = 15 * 2.3488; 
			use = use - 15;
	        energy += 10 * 2.9882;
	        use = use - 10;
	        energy += 10 * 3.2405;
	        use = use - 10;
	        energy += use * 3.6237;
	    }	    
		else if (unit > 100 && unit <= 150){
			energy = 15 * 2.3488; 
			use = use - 15;
	        energy += 10 * 2.9882;
	        use = use - 10;
	        energy += 10 * 3.2405;
	        use = use - 10;
	        energy += 65 * 3.6237;
	        use = use - 65;
	        energy += use * 3.7171;
	    }
	    else if (unit > 150 && unit <= 400){
	    	energy = 15 * 2.3488; 
			use = use - 15;
	        energy += 10 * 2.9882;
	        use = use - 10;
	        energy += 10 * 3.2405;
	        use = use - 10;
	        energy += 65 * 3.6237;
	        use = use - 65;
	        energy += 50 * 3.7171;
	        use = use - 50;
	        energy += use * 4.2218;
	    }
		else{
			energy = 15 * 2.3488; 
			use = use - 15;
	        energy += 10 * 2.9882;
	        use = use - 10;
	        energy += 10 * 3.2405;
	        use = use - 10;
	        energy += 65 * 3.6237;
	        use = use - 65;
	        energy += 50 * 3.7171;
	        use = use - 50;
	        energy += 250 * 4.2218;
	        use = use - 250;
	        energy += use * 4.4217;
	    }
	}
	else if(x==2){	
		if(unit > 400){
			energy = 150 * 3.2484;
			use = use - 150;
            energy = 250 * 4.2218;
			use = use - 250;
            energy += use * 4.4217;

	    }
	    else if(unit > 150 && unit <= 400){
	        energy = 150 * 3.2484;
			use = use - 150;
            energy += use * 4.2218;
	    }
	    else if(unit > 0 && unit <= 150){
	        energy += unit * 3.2484;
	    }
	}    
	else if(x==3){
		if (unit > 100){
			energy = 100 * 2.0889;
			use = use - 100;
	        energy += use * 3.2405;
	    }
	    else if (unit > 0 && unit <= 100){
	        energy += unit * 2.0889;
	    }
	}
	ans.energy = energy;
    ans.service = service;
	ans.total_ele = ans.energy + ans.service;
	ans.use_energy = unit * ft;
	ans.vat = (ans.use_energy + ans.total_ele) * 7 / 100;
	ans.total = ans.use_energy + ans.total_ele + ans.vat;
	display(ans);	
}
cal_2(int x,int on,int off,float service){
	float peak,offpeak,energy;
	if(x==1){
		peak = 5.1135, offpeak = 2.6037;
		energy = (on * peak) + (off * offpeak);	
	}
	else if(x==2){
		peak = 5.7982, offpeak = 2.6369;
		energy = (on * peak) + (off * offpeak);	
	} 
	ans.energy = energy;
    ans.service = service;
    ans.total_ele = ans.energy + ans.service;
    ans.use_energy = (on + off) * ft;
    ans.vat = (ans.total_ele + ans.use_energy) * 7 / 100;
    ans.total = ans.use_energy + ans.total_ele + ans.vat;
    display(ans);
}
cal_3(int x,int demand,int unit,float service,int reactive){
    float energy;
    if(x == 1){
    energy = (demand * 175.70) + (unit * 3.1097);	
	} 
    else if(x == 2){
    	energy = (demand * 196.26) + (unit * 3.1471);
	}
	else if(x == 3){
		energy = (demand * 221.50) + (unit * 3.1751);
	}   
	else if(x == 4){
		energy = (demand * 220.56) + (unit * 3.1097);
	}
	else if(x == 5){
		energy = (demand * 256.07) + (unit * 3.1471);
	}
	else if(x == 6){
		energy = (demand * 276.64) + (unit * 3.1751);
	}
	if(reactive==1){
		ans.reactive = reactive * 56.07;	
	}
	else{
		ans.reactive = (reactive * 56.07)-56.07 ;
	}
    ans.energy = energy;
    ans.service = service;
    ans.total_ele = ans.energy + ans.service + ans.reactive;
    ans.use_energy = unit * ft;
    ans.vat = (ans.total_ele + ans.use_energy) * 7 / 100;
    ans.total = ans.use_energy + ans.total_ele + ans.vat;
    display(ans);
}
cal_4(int x,int demand,int demand1,int on,int off,float service,int reactive){      
    float energy;
    if(x == 1){	
    	energy = (demand * 74.14) + (demand1 * 0) + (on * 4.1025) + (off * 2.5849);
    }
    else if(x == 2){
    	energy = (demand * 132.93) + (demand1 * 0) + (on * 4.1839) + (off * 2.6037);
	}
	else if(x == 3){
    	energy = (demand * 210.00) + (demand1 * 0) + (on * 4.3297) + (off * 2.6369);
	}   
	if(reactive>1){	
		ans.reactive = (reactive * 56.07)-56.07 ;
	}          
	ans.energy = energy;
    ans.service = service;
    ans.total_ele = ans.energy + ans.service + ans.reactive;
    ans.use_energy = ( on * ft ) + (off * ft);
    ans.vat = (ans.total_ele + ans.use_energy) * 7 / 100;
    ans.total = ans.use_energy + ans.total_ele + ans.vat;
    display(ans);
} 
cal_5(int on,int par,int off,int unit,float service,int reactive){
    float energy;
    energy = (on * 224.30) + ((par * 29.91)-29.91) + (off * 0) + (unit * 3.1097);
	if(reactive==1){
		ans.reactive = reactive * 56.07;	
	}
	else{
		ans.reactive = (reactive * 56.07)-56.07 ;
	}
    ans.energy = energy;
    ans.service = service;
    ans.reactive = reactive;
    ans.total_ele = ans.energy + ans.service + ans.reactive;
    ans.use_energy = unit * ft;
    ans.vat = (ans.total_ele + ans.use_energy) * 7 / 100;
    ans.total = ans.use_energy + ans.total_ele + ans.vat;
    display(ans);
}
cal_6(int unit,float service){
    int use;
    float energy;
    if (unit > 10)
    {
        use = unit - 10;
        energy += use * 3.8919;
        unit -= use;
    }
    else if (unit > 0 && unit <= 10)
    {
        energy += unit * 2.8013;
    }
	ans.energy = energy;
    ans.service = service;
    ans.total_ele = ans.energy + ans.service;
    ans.use_energy = unit * ft;
    ans.vat = (ans.use_energy + ans.total_ele) * 7 / 100;
    ans.total = ans.use_energy + ans.total_ele + ans.vat;
    display(ans);
}
cal_7(int x,int unit,float service){
    float energy;
    if(x==1){
    	energy = unit * 3.4149;
	}
	else if(x==2){
    	energy = unit * 3.5849;
	}
	else if(x==3){
    	energy = unit * 3.9086;
	}    
	else if(x==4){
    	energy = unit * 6.8025;
	}
	ans.energy = energy;
    ans.service = service;
    ans.total_ele = ans.energy + ans.service;
    ans.use_energy = unit * ft;
    ans.vat = (ans.use_energy + ans.total_ele) * 7 / 100;
    ans.total = ans.use_energy + ans.total_ele + ans.vat;
    display(ans);
}
Show_menu(){
	printf("\t---Electricity calculation program---\n");
	printf("Type 1 Residentail Service \n");
	printf("Type 2 Small General Service \n");
	printf("Type 3 Medium General Service \n");
	printf("Type 4 Large General Service \n");
	printf("Type 5 Specific Business Service \n");
	printf("Type 6 Non-profit organization \n");
	printf("Type 7 Water Pumping for Agricultural \n");
	printf("Type 8 Temporary Tariff\n");
}
main(){
    int type1,type2,type3,unit,demand,demand1,par,on,off,x,reactive;
    float service,total_ele,use_energy,vat,total,ans;
    char y;   
    do
    {
    	printf("\n");   	
    	Show_menu();    	
        printf("Enter type electic(1-8) : ");
        scanf("%d", &type1);
        MonandYear();
        switch (type1)
        {
        case 1:
            printf("\n  1.Residentail service(Normal tariff/Progressive rate)\n  2.Residentail service(TOU tariff)");
            printf("\nElectricity Tariff (1-2) : ");
            scanf("%d", &type2);
            switch (type2)
            {
            case 1:
                printf("\n  1.Use electic less than 150\n  2.Use electic more than 150");
                printf("\nCustomer Type (1-2) : ");
                scanf("%d", &type3);
                switch (type3)
                {
                case 1:
                    printf("Ft = %.4f bath/kwh", ft);
                    printf("\nCustomer Used Energy : ");
                    scanf("%d", &unit);
                    cal_1(1,unit,8.19);
                    break;
                case 2:
                    printf("Ft = %.4f bath/kwh", ft);
                    printf("\nCustomer Used Energy : ");
                    scanf("%d", &unit);
                    cal_1(2,unit,24.26); 
                    break;
            	}
            	break;
            case 2:
                printf("\n  1.Voltage 22-33 kV\n  2.Voltage less than 22 kV");
                printf("\nCustomer Type (1-2) : ");
                scanf("%d", &type3);
                switch (type3)
                {
                case 1:
                    printf("Ft = %.4f bath/kwh", ft);
                    printf("\nEnergy on peak : ");
                    scanf("%d", &on);
                    printf("Energy off peak : ");
                    scanf("%d", &off);
                    cal_2(1,on,off,312.24);
                    break;
                case 2:
                    printf("Ft = %.4f bath/kwh", ft);
                    printf("\nEnergy on peak : ");
                    scanf("%d", &on);
                    printf("Energy off peak : ");
                    scanf("%d", &off);
                    cal_2(2,on,off,24.26);                  
					break;    
				}
                break;
        	}
        	break;
        case 2:
            printf("\n  1.Small general service(Normal tariff/Progressive rate)\n  2.Small general service(TOU tariff)");
            printf("\nElectricity Tariff (1-2) : ");
            scanf("%d", &type2);
            switch (type2)
            {
            case 1:
                printf("\n  1.Voltage 22-33 kV\n  2.Voltage less than 22 kV");
                printf("\nCustomer Type (1-2) : ");
                scanf("%d", &type3);
                switch (type3)
				{				
            	case 1:
                    printf("Ft = %.4f bath/kwh", ft);
                    printf("\nCustomer Used Energy : ");
                    scanf("%d", &unit);
                    cal_7(3,unit,312.24);
                    break;             
                case 2:
                    printf("Ft = %.4f bath/kwh", ft);
                    printf("\nCustomer Used Energy : ");
                    scanf("%d", &unit);
                    cal_1(2,unit,33.29);
                    break;   
                }
                break; 
            case 2:
                printf("\n  1.Voltage 22-33 kV\n  2.Voltage less than 22 kV");
                printf("\nCustomer Type (1-2) : ");
                scanf("%d", &type3);
                switch (type3)
                {
                case 1:
                    printf("Ft = %.4f bath/kwh", ft);
                    printf("\nEnergy on peak : ");
                    scanf("%d", &on);
                    printf("Energy off peak : ");
                    scanf("%d", &off);
                    cal_2(1,on,off,312.24);
                    break;
                case 2:
                    printf("Ft = %.4f bath/kwh", ft);
                    printf("\nEnergy on peak : ");
                    scanf("%d", &on);
                    printf("Energy off peak : ");
                    scanf("%d", &off);
                    cal_2(2,on,off,33.29);
                    break;
                }
                break;
            }
            break;
		case 3:
            printf("\n  1.Medium general service(Normal tariff/Progressive rate)\n  2.Medium general service(TOU tariff)");
            printf("\nElectricity Tariff (1-2) : ");
            scanf("%d", &type2);
            switch (type2)
            {
            case 1:
                printf("\n  1.Voltage more than 69 kV\n  2.Voltage 22-33 kV\n  3.Voltage less than 22 kV");
                printf("\nCustomer Type (1-3) : ");
                scanf("%d", &type3);
                switch (type3)
                {
                case 1:
                    printf("Maximum electrical power demand : ");
                    scanf("%d", &demand);
                    printf("Enter Reactive power : ");
        			scanf("%d",&reactive);
                    printf("Customer Used Energy : ");
                    scanf("%d", &unit);
					cal_3(1,demand,unit,312.24,reactive);
                    break;
                case 2:
                    printf("Maximum electrical power demand : ");
                    scanf("%d", &demand);
                    printf("Enter Reactive power : ");
        			scanf("%d",&reactive);
                    printf("Customer Used Energy : ");
                    scanf("%d", &unit);
                    cal_3(2,demand,unit,312.24,reactive);
					break;
                case 3:
                    printf("Maximum electrical power demand : ");
                    scanf("%d", &demand);
                    printf("Enter Reactive power : ");
        			scanf("%d",&reactive);
                    printf("Customer Used Energy : ");
                    scanf("%d", &unit);
                    cal_3(3,demand,unit,312.24,reactive);                                     
                    break;
                }	
				break;
			case 2:
                printf("\n  1.Voltage more than 69 kV\n  2.Voltage 22-33 kV\n  3.Voltage less than 22 kV");
                printf("\nCustomer Type (1-3) : ");
                scanf("%d", &type3);
                switch (type3)
                {
                case 1:
				 	printf("Electrical power demand on peak : ");
				    scanf("%d", &demand);
				    printf("Electrical power demand off peak : ");
				    scanf("%d", &demand1);
				    printf("Enter energy on peak : ");
				    scanf("%d", &on);
				    printf("Enter energy off peak : ");
				    scanf("%d", &off);
				    printf("Enter Reactive power : ");
	        		scanf("%d",&reactive);
					cal_4(1,demand,demand1,on,off,312.24,reactive);
                    break;
                case 2:
				 	printf("Electrical power demand on peak : ");
				    scanf("%d", &demand);
				    printf("Electrical power demand off peak : ");
				    scanf("%d", &demand1);
				    printf("Enter energy on peak : ");
				    scanf("%d", &on);
				    printf("Enter energy off peak : ");
				    scanf("%d", &off);
				    printf("Enter Reactive power : ");
	        		scanf("%d",&reactive);
					cal_4(2,demand,demand1,on,off,312.24,reactive);
                    break;
                case 3:
				 	printf("Electrical power demand on peak : ");
				    scanf("%d", &demand);
				    printf("Electrical power demand off peak : ");
				    scanf("%d", &demand1);
				    printf("Enter energy on peak : ");
				    scanf("%d", &on);
				    printf("Enter energy off peak : ");
				    scanf("%d", &off);
				    printf("Enter Reactive power : ");
	        		scanf("%d",&reactive);
					cal_4(3,demand,demand1,on,off,312.24,reactive);
                    break;
                }
            }
            break;	
		case 4:
            printf("\n  1.Large general service(Normal tariff/Progressive rate)\n  2.Large general service(TOU tariff)");
            printf("\nElectricity Tariff (1-2) : ");
            scanf("%d", &type2);
            switch (type2)
            {
            case 1:
	            printf("Maximum electrical power demand(Peak) : ");
	            scanf("%d", &on);
	            printf("Maximum electrical power demand(Patial) : ");
	            scanf("%d", &par);
	            printf("Maximum electrical power demand(Off Peak) : ");
	            scanf("%d", &off);
	            printf("Enter Reactive power : ");
	        	scanf("%d",&reactive);
	            printf("Customer Used Energy : ");
	            scanf("%d", &unit);
	            cal_5(on,par,off,unit,312.24,reactive);
	            break;  
           	case 2:
                printf("\n  1.Voltage more than 69 kV\n  2.Voltage 22-33 kV\n  3.Voltage less than 22 kV");
                printf("\nCustomer Type (1-3) : ");
                scanf("%d", &type3);
                switch (type3)
                {
                case 1:
				 	printf("Electrical power demand on peak : ");
				    scanf("%d", &demand);
				    printf("Electrical power demand off peak : ");
				    scanf("%d", &demand1);
				    printf("Enter energy on peak : ");
				    scanf("%d", &on);
				    printf("Enter energy off peak : ");
				    scanf("%d", &off);
				    printf("Enter Reactive power : ");
	        	    scanf("%d",&reactive);
					cal_4(1,demand,demand1,on,off,312.24,reactive);
                    break;
                case 2:
				 	printf("Electrical power demand on peak : ");
				    scanf("%d", &demand);
				    printf("Electrical power demand off peak : ");
				    scanf("%d", &demand1);
				    printf("Enter energy on peak : ");
				    scanf("%d", &on);
				    printf("Enter energy off peak : ");
				    scanf("%d", &off);
				    printf("Enter Reactive power : ");
	        		scanf("%d",&reactive);
					cal_4(2,demand,demand1,on,off,312.24,reactive);
                    break;
                case 3:
				 	printf("Electrical power demand on peak : ");
				    scanf("%d", &demand);
				    printf("Electrical power demand off peak : ");
				    scanf("%d", &demand1);
				    printf("Enter energy on peak : ");
				    scanf("%d", &on);
				    printf("Enter energy off peak : ");
				    scanf("%d", &off);
				    printf("Enter Reactive power : ");
	        		scanf("%d",&reactive);
					cal_4(3,demand,demand1,on,off,312.24,reactive);
                    break;
                }
                break;
            }
            break;
		case 5:
            printf("\n  1.Specific business service(TOU tariff) \n  2.Specific business service(Not installed a TOU meter)");
            printf("\nElectricity Tariff (1-2) : ");
            scanf("%d", &type2);
            switch (type2)
            {
            case 1:
				printf("Maximum electrical power demand(Peak) : ");
				scanf("%d", &demand);
                printf("Enter Reactive power : ");
        		scanf("%d",&reactive);
                printf("Customer Used Energy : ");
                scanf("%d", &unit);
				cal_3(4,demand,unit,312.24,reactive);
                break;
            case 2:
                printf("\n  1.Voltage more than 69 kV\n  2.Voltage 22-33 kV\n  3.Voltage less than 22 kV");
                printf("\nCustomer Type (1-3) : ");
                scanf("%d", &type3);
                switch (type3)
                {
                case 1:
                    printf("Maximum electrical power demand : ");
                    scanf("%d", &demand);
                    printf("Enter Reactive power : ");
        			scanf("%d",&reactive);
                    printf("Customer Used Energy : ");
                    scanf("%d", &unit);
					cal_3(4,demand,unit,312.24,reactive);
                    break;
                case 2:
                    printf("Maximum electrical power demand : ");
                    scanf("%d", &demand);
                    printf("Enter Reactive power : ");
        			scanf("%d",&reactive);
                    printf("Customer Used Energy : ");
                    scanf("%d", &unit);
                    cal_3(5,demand,unit,312.24,reactive);
                    break;
                case 3:
                    printf("Maximum electrical power demand : ");
                    scanf("%d", &demand);
                    printf("Enter Reactive power : ");
        			scanf("%d",&reactive);
                    printf("Customer Used Energy : ");
                    scanf("%d", &unit);
                    cal_3(6,demand,unit,312.24,reactive);
                    break;
                }
                break;
            }
            break;
        case 6:
            printf("  1.Grovernment institution and non-profit organization(Normal tariff)\n  2.Grovernment institution and non-profit organization(TOU tariff)");
            printf("\nEnter type electricity tariff(1-2) : ");
            scanf("%d", &type2);
            switch (type2)
            {
            case 1:
                printf("  1.Voltage more than 69 kV\n  2.Voltage 22-33 kV\n  3.Voltage less than 22 kV");
                printf("\nCustomer Type (1-3) : ");
                scanf("%d", &type3);
                switch (type3)
                {
                case 1:
                    printf("Ft = %.4f bath/kwh", ft);
                    printf("\nCustomer Used Energy : ");
                    scanf("%d", &unit);
                    cal_7(1,unit,312.24);
                    break;
                case 2:
                    printf("Ft = %.4f bath/kwh", ft);
                    printf("\nCustomer Used Energy : ");
                    scanf("%d", &unit);
                    cal_7(2,unit,312.24);
                    break;
                case 3:
                    printf("Ft = %.4f bath/kwh", ft);
                    printf("\nCustomer Used Energy : ");
                    scanf("%d", &unit);
                    cal_6(unit,20.00);
                    break;
                }
                break;
            case 2:
                printf("  1.Voltage more than 69 kV\n  2.Voltage 22-33 kV\n  3.Voltage less than 22 kV");
                printf("\nCustomer Type (1-3) : ");
                scanf("%d", &type3);
                switch (type3)
                {
                case 1:
				 	printf("Electrical power demand on peak : ");
				    scanf("%d", &demand);
				    printf("Electrical power demand off peak : ");
				    scanf("%d", &demand1);
				    printf("Enter energy on peak : ");
				    scanf("%d", &on);
				    printf("Enter energy off peak : ");
				    scanf("%d", &off);
				    printf("Enter Reactive power : ");
	        		scanf("%d",&reactive);
					cal_4(1,demand,demand1,on,off,312.24,reactive);
                    break;
                case 2:
				 	printf("Electrical power demand on peak : ");
				    scanf("%d", &demand);
				    printf("Electrical power demand off peak : ");
				    scanf("%d", &demand1);
				    printf("Enter energy on peak : ");
				    scanf("%d", &on);
				    printf("Enter energy off peak : ");
				    scanf("%d", &off);
				    printf("Enter Reactive power : ");
	        		scanf("%d",&reactive);
					cal_4(2,demand,demand1,on,off,312.24,reactive);
                    break;
                case 3:
				 	printf("Electrical power demand on peak : ");
				    scanf("%d", &demand);
				    printf("Electrical power demand off peak : ");
				    scanf("%d", &demand1);
				    printf("Enter energy on peak : ");
				    scanf("%d", &on);
				    printf("Enter energy off peak : ");
				    scanf("%d", &off);
				    printf("Enter Reactive power : ");
	        		scanf("%d",&reactive);
					cal_4(3,demand,demand1,on,off,312.24,reactive);
                    break;
                }
                break;
            }
            break;
        case 7:
            printf("  1.Water pumping for agricultural purposes(Normal tariff)\n  2.Water pumping for agricultural purposes(TOU tariff)");
            printf("\nElectricity Tariff (1-2) : ");
            scanf("%d", &type2);
            switch (type2)
            {
            case 1:
                printf("Ft = %.4f bath/kwh", ft);
                printf("\nCustomer Used Energy : ");
                scanf("%d", &unit);
                cal_1(3,unit,115.16);
                break;
            case 2:
                printf("  1.Voltage 22-33 kV\n  2.Voltage less than 22 kV");
                printf("\nCustomer Type (1-2) : ");
                scanf("%d", &type3);
                switch (type3)
                {
                case 1:
				 	printf("Electrical power demand on peak : ");
				    scanf("%d", &demand);
				    printf("Electrical power demand off peak : ");
				    scanf("%d", &demand1);
				    printf("Enter energy on peak : ");
				    scanf("%d", &on);
				    printf("Enter energy off peak : ");
				    scanf("%d", &off);
				    printf("Enter Reactive power : ");
	        		scanf("%d",&reactive);
					cal_4(2,demand,demand1,on,off,204.07,reactive);
                    break;
                case 2:
				 	printf("Electrical power demand on peak : ");
				    scanf("%d", &demand);
				    printf("Electrical power demand off peak : ");
				    scanf("%d", &demand1);
				    printf("Enter energy on peak : ");
				    scanf("%d", &on);
				    printf("Enter energy off peak : ");
				    scanf("%d", &off);
				    printf("Enter Reactive power : ");
	        		scanf("%d",&reactive);
					cal_4(3,demand,demand1,on,off,204.07,reactive);
                    break;
                }
                break;
            }
            break;
        case 8:
            printf("Ft = %.4f bath/kwh", ft);
            printf("\nCustomer Used Energy : ");
            scanf("%d", &unit);
            cal_7(4,unit,0);	
	        break;
	    default:
	        break;
	    }
    printf("\nProcess again? (Y/N) : ");
    y = getche();
    }while (y == 'Y' || y == 'y');
    printf("\n\t    ---End Electricity calculation program--- ");
}