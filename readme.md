# miniRT

### Resolution
there must be a single resolution declared in the scene, if the programm is runing in a window, it will fit the max size of the screen

usage :
| "R" | x<0,16384> | y<0,16384> |
| --- | ---------- | ---------- |

example :
```
R	1920	1080
```

----------

### Ambient light
you can declare only one ambient light, if no one is declared, a default black ambient light should be used

usage :
| "A" | intensity[-1,1] | color<r,g,b>[0,255] |
| --- | --------------- | ------------------- |

example :
```
A	0.2		255,255,255
```

----------

### Cameras
You can declare any cams you want but it must be a least one
the first cam declared is the default cam and is the only one used with `--save`

usage :
| "C" | position<x,y,z> | rotation<x,y,z>[-1,1] | FOV[0,180] |
| --- | --------------- | --------------------- | ---------- |

example :
```
C	-50,0,25	0,0,1	70
```

----------

### Lights
You can declare any lights you want

usage :
| "l" | position<x,y,z> | intensity[0,1] | color<r,g,b>[0,255] |
| --- | --------------- | -------------- | ------------------- |

example :
```
l	-40,50,0	0.6		10,0,255
```

----------

### Spheres

usage :
| "sp" | position<x,y,z> | diameter | color<r,g,b>[0,255] |
| ---- | --------------- | -------- | ------------------- |

example :
```
sp	0,0,20.6	12.6	10,0,255
```

----------

### Planes

usage :
| "pl" | position<x,y,z> | rotation<x,y,z>[-1,1] | color<r,g,b>[0,255] |
| ---- | --------------- | --------------------- | ------------------- |

example :
```
pl	0,0,-10		0,1,0	0,0,255
```

----------

### Squares

usage :
| "sq" | position<x,y,z> | rotation<x,y,z>[-1,1] | size | color<r,g,b>[0,255] |
| ---- | --------------- | --------------------- | ---- | ------------------- |

example :
```
sq	0,0,20.6	1,0,0	12.6	255,0,255
```

----------

### Cylinder

usage :
| "cy" | position<x,y,z> | rotation<x,y,z>[-1,1] | diameter | height | color<r,g,b>[0,255] |
| ---- | --------------- | --------------------- | -------- | ------ | ------------------- |

example :
```
cy	50,0,20,6	0,0,1	14.2	21.42	10,0,255
```

----------

### Triangle

usage :
| "tr" | p1<x,y,z> | p2<x,y,z> | p3<x,y,z> | color<r,g,b>[0,255] |
| ---- | --------- | --------- | --------- | ------------------- |

example :
```
tr	10,20,10	10,10,20	20,10,10	0,0,255
```

----------

## **Following part is not requested in the subject**

### Triangle

usage :
| "tr" | p1<x,y,z> | p2<x,y,z> | p3<x,y,z> | color<r,g,b>[0,255] |
| ---- | --------- | --------- | --------- | ------------------- |

example :
```
tr	10,20,10	10,10,20	20,10,10	0,0,255
```
