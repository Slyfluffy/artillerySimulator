#include "projectile.h"

// Default constructor
Projectile::Projectile() {
	this->p = Position();
	this->v = Velocity();
}

// Linear interpolations
double Projectile::linearInterpolation(float x, float x0, float x1, float y0, float y1) { 
	return y0 + (x - x0) * (y1 - y0) / (x1 - x0); 
}

double Projectile::linearInterpolation(const Mapping & zero, const Mapping & one, float d) { 
	return linearInterpolation(d, zero.domain, one.domain, zero.range, one.range);
}
double Projectile::linearInterpolation(const Mapping map[], int numMapping, float domain) { 
	if (domain < map[0].domain)
		return map[0].range;

	for (int i = 0; i < numMapping - 1; i++) {
		if (map[i + 0].domain <= domain && domain <= map[i + 1].domain)
			return linearInterpolation(map[i + 0], map[i + 1], domain);
	}

	return map[numMapping - 1].range;
}

double Projectile::computeAirDensity(float altitude) { 
    const Mapping densityMap[] =
    {
       {  0.0 , 1.225    },
       {  1000, 1.112    },
       {  2000, 1.007    },
       {  3000, .9093    },
       {  4000, .8194    },
       {  5000, .7364    },
       {  6000, .6601    },
       {  7000, .5900    },
       {  8000, .5258    },
       {  9000, .4671    },
       { 10000, .4135    },
       { 15000, .1948    },
       { 20000, .08891   },
       { 25000, .04008   },
       { 30000, .01841   },
       { 40000, .003996  },
       { 50000, .001027  },
       { 60000, .0003097 },
       { 70000, .0000828 },
       { 80000, .0000185 }
    };

    cout << "Result: " << linearInterpolation(densityMap, sizeof(densityMap) / sizeof(densityMap[0]), altitude) << endl;

    // Check for the value in the table
    for (int i = 0; i < sizeof(densityMap); i++) {
        if (densityMap[i].domain == altitude)
            return densityMap[i].range;
    }

    
    return linearInterpolation(densityMap, sizeof(densityMap) / sizeof(densityMap[0]), altitude);
}
float Projectile::computeVelocitySound(float altitude) {
    const Mapping sMap[] =
    {
       {  0.0 , 340 },
       {  1000, 336 },
       {  2000, 332 },
       {  3000, 328 },
       {  4000, 324 },
       {  5000, 320 },
       {  6000, 316 },
       {  7000, 312 },
       {  8000, 308 },
       {  9000, 303 },
       { 10000, 299 },
       { 15000, 295 },
       { 20000, 295 },
       { 25000, 295 },
       { 30000, 305 },
       { 40000, 324 }
    };

    cout << "Result: " << linearInterpolation(sMap, sizeof(sMap) / sizeof(sMap[0]), altitude) <<  endl;

    for (int i = 0; i < sizeof(sMap); i++) {
        if (sMap[i].domain == altitude)
            return sMap[i].range;
    }

    return linearInterpolation(sMap, sizeof(sMap) / sizeof(sMap[0]), altitude);
}

float Projectile::computeGravity(float altitude) {
    float e = (6371009 / (6371009 + altitude));
    cout << "Result: " << 9.807 * (e * e) << endl; 
    return 9.807 * (e * e);
}
float Projectile::computeCoefficient(float v, float vSound) {
    float mach = v / vSound;

    const Mapping cMap[] =
    {
       {  0.3, .1629 },
       {  0.5, .1659 },
       {  0.7, .2031 },
       { 0.89, .2597 },
       { 0.92, .3010 },
       { 0.96, .3287 },
       { 0.98, .4002 },
       { 1.00, .4258 },
       { 1.02, .4335 },
       { 1.06, .4483 },
       { 1.24, .4064 },
       { 1.53, .3663 },
       { 1.99, .2897 },
       { 2.87, .2297 },
       { 2.89, .2306 },
       { 5.00, .2656 }
    };

    cout << "Result: " << linearInterpolation(cMap, sizeof(cMap) / sizeof(cMap[0]), mach) << endl;

    for (int i = 0; i < sizeof(cMap); i++) {
        if (cMap[i].domain == mach)
            return cMap[i].range;
    }

    return linearInterpolation(cMap, sizeof(cMap) / sizeof(cMap[0]), mach);
}
