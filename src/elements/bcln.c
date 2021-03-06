#include <element.h>

int update_BCLN(UPDATE_FUNC_ARGS) {
	if (!parts[i].life && pv[y/CELL][x/CELL]>4.0f)
		parts[i].life = rand()%40+80;
	if (parts[i].life)
	{
		float advection = 0.1f;
		parts[i].vx += advection*vx[y/CELL][x/CELL];
		parts[i].vy += advection*vy[y/CELL][x/CELL];
	}
	if (parts[i].ctype<=0 || parts[i].ctype>=PT_NUM)
	{
		int r, rx, ry;
		for (rx=-1; rx<2; rx++)
			for (ry=-1; ry<2; ry++)
				if (x+rx>=0 && y+ry>=0 && x+rx<XRES && y+ry<YRES)
				{
					r = photons[y+ry][x+rx];
					if (!r || (r>>8)>=NPART)
						r = pmap[y+ry][x+rx];
					if (!r || (r>>8)>=NPART)
						continue;
					if ((r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN &&
				        (r&0xFF)!=PT_BCLN && (r&0xFF)!=PT_STKM &&
				        (r&0xFF)!=PT_STKM2 && (r&0xFF)!=PT_PBCN &&
				        (r&0xFF)<PT_NUM)
					parts[i].ctype = r&0xFF;
				}
	}
	else {
		create_part(-1, x+rand()%3-1, y+rand()%3-1, parts[i].ctype);
	}
	return 0;
}
