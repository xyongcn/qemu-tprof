#!/bin/bash
 
DPATH="/sys/kernel/debug/tracing"
PID=$$
 
# flush existing trace data
echo nop > $DPATH/current_tracer
 
# set function tracer
echo function_graph > $DPATH/current_tracer

# enable the current tracer
echo 1 > $DPATH/tracing_enabled
 
# write current process id to set_ftrace_pid file
echo $PID > $DPATH/set_ftrace_pid

echo nofuncgraph-duration > $DPATH/trace_options

echo funcgraph-proc > $DPATH/trace_options
echo 1 > $DPATH/events/raw_syscalls/enable
 
# start the tracing
echo 1 > $DPATH/tracing_on
# execute the process
exec $*
