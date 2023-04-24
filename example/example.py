import pypre
params = pypre.CurveParams()
sk = pypre.SK_PRE1()
pk = pypre.PK_PRE1()

print("generate params",pypre.PRE1_generate_params(params))
print("key gen", pypre.PRE1_keygen(params,pk,sk))