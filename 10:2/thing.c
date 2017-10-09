int
getprocs(struct ProcessInfo* processInfoTable)
{
  struct proc *p;
  int i;
  int result = 0;
  for (p = ptable.proc, i = 0; p < &ptable.proc[NPROC] && i < NPROC; p++, i++) {
    if (p->state == UNUSED) continue;
    result++;
    processInfoTable[i].pid = p->pid;
    processInfoTable[i].ppid = (i == 0) ? -1 : p->parent->pid;
    processInfoTable[i].state = p->state;
    processInfoTable[i].sz = p->sz;
    int j;
    for (j = 0; j < 16; j++) processInfoTable[i].name[j] = p->name[j];
  }
  p = NULL;
  return result;
}

