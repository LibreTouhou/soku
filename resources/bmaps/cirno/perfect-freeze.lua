local PerfectFreeze = {}

PerfectFreeze.n = 300

PerfectFreeze.shape = "block"

PerfectFreeze.start = []
PerfectFreeze.speed = []
PerfectFreeze.dir1 = []
PerfectFreeze.dir2 = []

-- smooth used for fighting against crowding in top and bottom of sphere
local function smooth(value)
  if value < 0.5 then
    return math.pow(2*value, 1/3) / 2
  else
    return (-math.pow(math.abs(2*value-2), 1/3) + 2) / 2
  end
end

function PerfectFreeze.init(i)
  start[i] = (4*i) / PerfectFreeze.n
  speed[i] = math.random(4, 7)

  local phi1 = math.random()
  local theta1 = smooth(math.random())

  -- first direction used when comeing from unit
  dir1[i] = {
    x = math.sin(phi1 * 2 * math.pi) * math.sin(theta1 * math.pi),
    y = math.cos(theta1 * math.pi),
    z = math.cos(phi1 * 2 * math.pi) * math.sin(theta1 * math.pi)
  }

  local phi2 = math.random()
  local theta2 = smooth(math.random())

  -- second direction used after freeze
  dir2[i] = {
    x = math.sin(phi2 * 2 * math.pi) * math.sin(theta2 * math.pi),
    y = math.cos(theta2 * math.pi),
    z = math.cos(phi2 * 2 * math.pi) * math.sin(theta2 * math.pi)
  }
end

function PerfectFreeze.position(i, t)
  _t = t - self.start
  stop = 5 - self.start
  if t < 7 then
    x = math.min(stop, _t) * speed[i] * dir1[i].x
    y = math.min(stop, _t) * speed[i] * dir1[i].y
    z = math.min(stop, _t) * speed[i] * dir1[i].z
    return x, y, z
  else
    base = {
      x = stop * speed[i] * dir1[i].x,
      y = stop * speed[i] * dir1[i].y,
      z = stop * speed[i] * dir1[i].z
    }
    x = base.x + math.pow(t-7, 2) * dir2[i].x
    y = base.y + math.pow(t-7, 2) * dir2[i].y
    z = base.z + math.pow(t-7, 2) * dir2[i].z
    return x, y, z
  end
end

return PerfectFreeze
