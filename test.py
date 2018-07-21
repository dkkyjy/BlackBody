import numpy as np
import matplotlib.pyplot as plt
from BlackBody import Planck, RJ, Wien

nu = np.logspace(5, 20, 100)
for T in [1e0, 1e2, 1e4, 1e6, 1e8]:
    Planck_nu = Planck(nu, T)
    RJ_nu = RJ(nu, T)
    Wien_nu = Wien(nu, T)

    plt.loglog(nu, Planck_nu, label='T = {:1}K'.format(T))
    plt.loglog(nu, RJ_nu, label='RJ')
    plt.loglog(nu, Wien_nu, label='Wien')
plt.legend()
plt.xlim(1e5, 1e20)
plt.ylim(1e-20, 1e10)
plt.xlabel(r'$\nu$ (Hz)')
plt.ylabel(r'$B_{\nu}$(T)')
plt.show()
