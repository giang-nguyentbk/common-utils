# commonUtils

## TraceIf (this is a Trace Point Tracking system)
```
It's designed based on:
	+ vsnprintf(): to get printf() variadic parameters.
	+ localtime(): to get high-resolution local timestamp (up to nano seconds).
	+ Macros __FILE__, __LINE__.
	+ prctl(): to get thread name
	+ getcpu(): to get cpu id (processor's core id). 
```

![TraceIf](./assets/traceIf.png?raw=true)