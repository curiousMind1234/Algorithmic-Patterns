Path Sum → "Does a path exist?" → return = answer itself (bool), target subtracted on the way down

LCA → "Where do two nodes split?" → return = a node, decide using both-found / one-found / none-found

Diameter → "Longest path anywhere" → return = height, real answer = maxDia, updated via left+right

Balanced Tree → "Is every node's left/right height gap ≤ 1?" → return = height OR -1 sentinel, -1 short-circuits upward

Max Path Sum → "Diameter, but with values, and negatives can hurt" → return = root.val + better single branch (clamped ≥0), maxSum = root.val + both branches
