from timeit import repeat
from subprocess import check_output
def timer(arg, niter, name, module):
    stmt = "%s(%s)" % (name, arg)
    setup = "from %s import %s" % (module, name)
    time = min(repeat(stmt=stmt, setup=setup,
    number=niter)) / float(niter) * 1e9
    return time

N = 10**6
pytime_0 = timer(0, N, name='fib', module='fib')
cytime_0 = timer(0, N, name='fib', module='cyfib')
ctime_0 = float(check_output(('./cfib.x 0 %d' %
N).split()))
py0speedup = 1.0
cy0speedup = pytime_0 / cytime_0
c0speedup = pytime_0 / ctime_0

N = 10**5
pytime_90 = timer(90, N, name='fib', module='fib')
cytime_90 = timer(90, N, name='fib',
module='cyfib')
ctime_90 = float(check_output(('./cfib.x 90 %d' %
N).split()))
py90speedup = 1.0
cy90speedup = pytime_90 / cytime_90
c90speedup = pytime_90 / ctime_90

N = 10**6
pytime_120 = timer(120, N, name='fib', module='fib')
cytime_120 = timer(120, N, name='fib',
module='cyfib')
ctime_120 = float(check_output(('./cfib.x 120 %d' %
N).split()))
py120speedup = 1.0
cy120speedup = pytime_120 / cytime_120

c120speedup = pytime_120 / ctime_120


pytime_150 = timer(150, N, name='fib', module='fib')
cytime_150 = timer(150, N, name='fib',
module='cyfib')
ctime_150 = float(check_output(('./cfib.x 150 %d' %N).split()))
py150speedup = 1.0
cy150speedup = pytime_150 / cytime_150

c150speedup = pytime_150 / ctime_150


pytime_180 = timer(180, N, name='fib', module='fib')
cytime_180 = timer(180, N, name='fib',
module='cyfib')
ctime_180 = float(check_output(('./cfib.x 180 %d' %
N).split()))
py180speedup = 1.0
cy180speedup = pytime_180 / cytime_180

c180speedup = pytime_180 / ctime_180

data_format = "{:s},{:.0f},{:.1f},{:.0f},{:.1f},{:.0f},{:.1f},{:.0f},{:.1f},{:.0f},{:.1f}\n"

with open("fib0.csv", 'w') as fh:
    fh.write("Version,fib(0) runtime [ns],speedup,fib(90) runtime [ns],speedup 90,fib(120) runtime [ns],speedup 120,fib(150) runtime [ns],speedup 150,fib(180) runtime [ns],speedup 180\n")
    fh.write(data_format.format("Python", pytime_0, py0speedup, pytime_90, py90speedup,pytime_120, py120speedup,pytime_150,py150speedup,pytime_180,py180speedup))
    fh.write(data_format.format("Cython", cytime_0, cy0speedup, cytime_90, cy90speedup,cytime_120,cy120speedup,cytime_150,cy150speedup,cytime_180,cy180speedup))
    fh.write(data_format.format("Pure C", ctime_0, c0speedup, ctime_90, c90speedup,ctime_120,c120speedup,ctime_150,c150speedup,ctime_180,c180speedup))