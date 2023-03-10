def dfs(node, level):
    level_xor[level] ^= vals[node]
    max_level_xor[level] = max(max_level_xor[level], level_xor[level])
    for child in tree[node]:
        dfs(child, level + 1)

n = int(input())
vals = [0] + list(map(int, input().split()))
tree = {i: [] for i in range(1, n + 1)}
for _ in range(n - 1):
    u, v = map(int, input().split())
    tree[u].append(v)
    tree[v].append(u)

level_xor = [0] * (n + 1)
max_level_xor = [0] * (n + 1)

dfs(1, 0)

for level in range(2, n + 1):
    nodes = [node for node in tree if level_xor[level - 1] & vals[node] != 0 and level_xor[level - 1] ^ vals[node] > 0]
    if len(nodes) >= 2:
        node1, node2 = nodes[:2]
        max_level_xor[level] = max(max_level_xor[level], level_xor[level - 1] ^ vals[node1] ^ vals[node2])

print(' '.join(str(max_level_xor[level]) for level in range(1, n + 1)))