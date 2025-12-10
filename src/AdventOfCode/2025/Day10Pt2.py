import sys, re
from ortools.sat.python import cp_model

def solve_instance(opts, target):
  m = cp_model.CpModel()
  ub = sum(target)
  x = [m.NewIntVar(0, ub, f"x{i}") for i in range(len(opts))]
  for j, t in enumerate(target):
    m.Add(sum(x[i] for i, o in enumerate(opts) if j in o) == t)
  m.Minimize(sum(x))
  s = cp_model.CpSolver()
  s.Solve(m)
  return int(s.ObjectiveValue())

total = 0
for line in sys.stdin:
  line = line.strip()

  # da skippare: [#..####.]
  parts = line.split(maxsplit=1)
  rest = parts[1]  # tutto dopo il primo spazio

  # vettori: (1,3,4,5,6,7)
  vecs = re.findall(r'\(([^)]*)\)', rest)
  opts = [list(map(int, v.split(','))) for v in vecs]

  # target: {30,55,16,43,62,29,26,44}
  targ_match = re.search(r'\{([^}]*)\}', rest)
  targ_str = targ_match.group(1)
  target = list(map(int, targ_str.split(',')))

  total += solve_instance(opts, target)

print(total)